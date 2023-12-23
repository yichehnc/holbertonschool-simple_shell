#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stddef.h>
#include "shell.h"

int _execute_args(char **args)
{
	char *builtin_funcs_list[] = {"cd", "help", "exit", "env"};

	int (*builtin_funcs[])(char **) = {
	    &shell_cd,
	    &shell_help,
	    &shell_exit,
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
