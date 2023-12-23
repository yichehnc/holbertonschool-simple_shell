#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stddef.h>
#include "shell.h"

/**
 * _execute_args - Execute a command or a built-in function.
 * @args: An array of strings representing the command and its arguments.
 *
 * Description:
 * This function takes an array of strings (@args) representing the command
 *  and its arguments.
 * It checks if the command is a built-in function
 * (e.g., "cd", "help", "exit", "env").
 * If it is, the corresponding built-in function is executed.
 * Otherwise, the command is assumed to be an external command, and a new
 * process is created
 * to execute it using the run_new_process function.
 *
 * Parameters:
 * @args: An array of strings representing the command and its arguments.
 *
 * Return:
 * On success, the return value depends on the executed command or function.
 * If the command is a built-in function, the return value is the result of
 * the built-in function.
 * If the command is an external command, the return value is the exit status
 * of the new process.
 * On failure or if @args[0] is NULL, the return value is -1.
 */
int _execute_args(char **args)
{
	char *builtin_funcs_list[] = {"cd", "help", "exit"};

	int (*builtin_funcs[])(char **) = {
	    &shell_cd,
	    &shell_help,
	    &shell_exit};

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
