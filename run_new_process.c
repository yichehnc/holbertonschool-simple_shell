#include "shell.h"

/**
 * handle_subprocess_error - Handle errors in subprocess execution.
 * @error_num: Error number indicating the type of error.
 *
 * Description:
 * Prints an error message based on the given error number during subprocess
 * execution and exits the process with the corresponding status. Handles
 * specific errors (EACCES, ENOENT, ENOMEM) and uses strerror for others.
 *
 * Parameters:
 * @error_num: Error number indicating the type of error.
 *
 * Return:
 * Exits the process with the appropriate status based on the error.
 */
void handle_subprocess_error()
{
	switch (errno)
	{
	case EACCES:
		fprintf(stderr, "execve failed: Permission denied\n");
		exit(126);
		break;
	case ENOENT:
		fprintf(stderr, "execve failed: File not found\n");
		exit(127);
		break;
	case ENOMEM:
		fprintf(stderr, "execve failed: Not enough memory\n");
		exit(128);
		break;
	default:
		fprintf(stderr, "execve failed: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_execution - Handle execution of a command in a subprocess.
 * @filepath: Full path to the command executable.
 * @args: Array of strings representing command arguments.
 * @environ: Array of strings representing the environment variables.
 * @status: Pointer to the status variable to store the subprocess status.
 *
 * Description:
 * Creates a subprocess using fork(), executes the specified command with the
 * given arguments and environment variables using execve(). Handles subprocess
 * errors and waits for the subprocess to complete. Updates the status
 * variable.
 *
 * Parameters:
 * @filepath: Full path to the command executable.
 * @args: Array of strings representing command arguments.
 * @environ: Array of strings representing the environment variables.
 * @status: Pointer to the status variable to store the subprocess status.
 *
 * Return:
 * No explicit return. Updates the status variable with subprocess completion
 * status.
 */
void handle_execution(char *filepath, char **args, char **environ, int *status)
{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(filepath, args, environ) == -1)
		{
			handle_subprocess_error(errno);
		}
	}
	else if (child_pid < 0)
	{
		perror("fork failed: ");
	}
	else
	{
		do
		{
			waitpid(child_pid, status, WUNTRACED);
		} while (!WIFEXITED(*status) && !WIFSIGNALED(*status));
	}
}

/**
 * run_new_process - Execute a command in a new process.
 * @args: Array of strings representing command and its arguments.
 *
 * Description:
 * Creates a new process using fork(), determines the full path of the command,
 * executes it using handle_execution(), and returns the exit status.
 *
 * Parameters:
 * @args: Array of strings representing command and its arguments.
 *
 * Return:
 * Exit status of the executed command.
 */
int run_new_process(char **args)
{
	int status;
	char *command = args[0], exec_path_abs[1024], *filepath = NULL;
	const char *executable_filename;
	ssize_t len;
	struct stat st;

	filepath = get_filepath(command);

	if (filepath == NULL)
	{
		if (strchr(command, '/') != NULL && stat(command, &st) == 0)
		{
			filepath = strdup(command);
		}
		else
		{
			len = readlink("/proc/self/exe", exec_path_abs, sizeof(exec_path_abs) - 1);

			if (len != -1)
			{
				exec_path_abs[len] = '\0';
				executable_filename = get_filename(exec_path_abs);
			}
			else
			{
				perror("Error getting executable path");
				return (EXIT_FAILURE);
			}
			fprintf(stderr, "./%s: 1: %s: not found\n", executable_filename, command);
			return (127);
		}
	}

	handle_execution(filepath, args, environ, &status);

	free(filepath);

	return (WEXITSTATUS(status));
}
