#include "shell.h"

int run_new_process(char **args)
{
	pid_t pid;
	int status;
	char *filename = args[0];
	char *filepath = NULL;

	if (strchr(args[0], '/'))
	{
		filepath = args[0];
	}
	else
	{
		filepath = findFileInPath(filename);
	}

	if (filepath != NULL)
	{
		pid = fork();

		if (pid == 0)
		{
			if (execvp(filepath, args) == -1)
			{
				perror("error _execute_command: child process");
			}
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("error in _execute_command: forking");
		}
		else
		{
			do
			{
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	else
	{
		fprintf(stderr, "%s: %d: %s: not found\n", "./shell", 1, args[0]);
		exit(127);
	}

	return (-1);
}