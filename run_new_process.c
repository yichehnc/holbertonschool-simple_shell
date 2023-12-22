#include "shell.h"

int run_new_process(char **args)
{
	pid_t pid;
	int status;
	char *command = args[0];
	const char *executable_filename;
	char *filepath = get_filepath(command);

	char exec_path_abs[1024];

	ssize_t len = readlink("/proc/self/exe", exec_path_abs, sizeof(exec_path_abs) + 1);

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
		/*errmsg_length = strlen(__FILE__) + strlen(command) + 17;
		errmsg = malloc(errmsg_length * sizeof(char));
		snprintf(errmsg, errmsg_length, "/%s: 1: %s: not found", __FILE__, command);
		perror(errmsg);*/
		fprintf(stderr, "./%s: 1: %s: not found\n", executable_filename, command);
	}
	else
	{
		pid = fork();

		if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("error _execute_command: child process");
				exit(EXIT_FAILURE);
			}
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
	return (-1);
}
