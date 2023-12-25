#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stddef.h>
#include "shell.h"

/**
 * _execute_args - Execute a command or a built-in function based on arguments.
 * @args: Array of strings representing the command and its arguments.
 *
 * Description:
 * This function evaluates the command specified in the args array and either
 * executes a built-in function or a new process. It checks for built-in
 * functions
 * such as cd, help, exit, and env. If the command is a built-in function, it
 * calls the corresponding function; otherwise, it runs a new process.
 *
 * Parameters:
 * @args: Array of strings representing the command and its arguments.
 *
 * Return:
 * Returns the exit status of the executed command or built-in function.
 */
int _execute_args(char **args)
{
	char *builtin_funcs_list[] = {"cd", "help", "env"};

	int (*builtin_funcs[])(char **) = {
	    &shell_cd,
	    &shell_help,
	    &shell_env};

	unsigned int i;

	if (args[0] == NULL)
	{
		return (-1);
	}

	for (i = 0; i < sizeof(builtin_funcs_list) / sizeof(char *); i++)
	{
		if (strcmp(args[0], builtin_funcs_list[i]) == 0)
		{
			return ((*builtin_funcs[i])(args));
		}
	}

	return (run_new_process(args));
}
