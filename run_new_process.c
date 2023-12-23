#include "shell.h"

/**
 * handle_error - Print an error message based on the given error number.
 * @error_number: The error number to handle.
 *
 * Description:
 * Prints an error message to stderr based on the provided error number.
 * Exits the program with a corresponding exit status.
 *
 * Parameters:
 * @error_number: The error number to handle.
 */
void handle_error(int error_number)
{
	switch (error_number)
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
 * wait_for_child - Wait for child process to exit or be terminated.
 * @child_pid: Process ID of the child.
 * @status: Pointer to store exit status or termination signal.
 *
 * Waits until the specified child process (child_pid) exits or is
 * terminated by a signal, updating the status variable accordingly.
 */
void wait_for_child(pid_t child_pid, int *status)
{
	while (1)
	{
		waitpid(child_pid, status, WUNTRACED);
		if (WIFEXITED(*status) || WIFSIGNALED(*status))
		{
			break;
		}
	}
}

/**
 * run_new_process - Execute a new process based on the given arguments.
 * @args: Array of strings representing the command and its arguments.
 *
 * Return: Exit status of the executed process.
 */
int run_new_process(char **args)
{
	pid_t child_pid;
	int status;
	char *command = args[0], *filepath, exec_path_abs[1024];
	const char *executable_filename;
	ssize_t len;

	filepath = get_filepath(command);
	if (filepath == NULL)
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
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(filepath, args, environ) == -1)
			handle_error(errno);
	}
	else if (child_pid < 0)
		perror("fork failed: ");
	else
	{
		wait_for_child(child_pid, &status);
	}
	free(filepath);
	return (WEXITSTATUS(status));
}
