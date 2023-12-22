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
				if (filepath != NULL)
				{
					free(filepath);
					filepath = NULL;
				}
				perror("error _run_new_process: child process");
			}
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("error in _execute_command: forking");
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("Error waiting for child process");
				exit(EXIT_FAILURE);
			}

			/* Check if the child process exited normally */
			if (WIFEXITED(status) == 0)
			{
				/* Print the exit status */
				printf("Child process exited with status %d\n", WEXITSTATUS(status));
				free(filepath);
			}
		}
	}
	else
	{
		fprintf(stderr, "%s: %d: %s: not found\n", "./shell", 1, args[0]);
		exit(127);
	}

	return (-1);
}