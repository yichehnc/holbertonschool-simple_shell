#include "shell.h"

extern char **environ;

int run_new_process(char **args)
{
	pid_t child_pid;
	int status;
	char *command = args[0];
	const char *executable_filename;
	char *filepath;
	char exec_path_abs[1024];
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
			return EXIT_FAILURE;
		}
		fprintf(stderr, "./%s: 1: %s: not found\n", executable_filename, command);
		exit(127);
	}
	else
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			if (execve(filepath, args, environ) == -1)
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
