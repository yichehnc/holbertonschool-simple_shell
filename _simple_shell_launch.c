#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stddef.h>

int simple_shell_launch(char **args)
{
	pid_t pid, w_pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("simple_shell _execute_command:");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("simple_shell _execute_command");
	}
	else
	{
		do
		{
			w_pid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}