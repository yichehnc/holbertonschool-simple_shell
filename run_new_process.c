#include "shell.h"

int run_new_process(char **args)
{
	pid_t child_pid;
	int status;
	char *command = args[0];
	const char *executable_filename;
	char *filepath;
	struct stat st;
	char exec_path_abs[1024];
	ssize_t len;

	if (stat(command, &st) == 0)
	{
		filepath = strdup(command);
	}
	else
	{
		filepath = get_filepath(command);
	}

	len = readlink("/proc/self/exe", exec_path_abs, sizeof(exec_path_abs) + 1);

	if (len != -1)
	{
		exec_path_abs[len] = '\0';
		executable_filename = get_filename(exec_path_abs);
	}
	else
	{
		perror("Error getting executable path");
		return EXIT_FAILURE;
	}

	if (filepath == NULL)
	{
		fprintf(stderr, "./%s: 1: %s: not found\n", executable_filename, command);
	}
	else
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			if (execvp(filepath, args) == -1)
			{
				perror("execvp failed: ");
				exit(EXIT_FAILURE);
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
				waitpid(child_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}

		free(filepath);
	}
	return child_pid > 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
