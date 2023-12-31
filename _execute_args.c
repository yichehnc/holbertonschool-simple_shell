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

	BuiltinFunction builtin_funcs[] = {
	    {"cd", &shell_cd},
	    {"help", &shell_help},
	    {"env", &shell_env}};

	unsigned int i;

	for (i = 0; i < sizeof(builtin_funcs) / sizeof(BuiltinFunction); i++)
	{
		if (strcmp(args[0], builtin_funcs[i].name) == 0)
		{
			return (builtin_funcs[i].func(args));
		}
	}

	return (run_new_process(args));
}
