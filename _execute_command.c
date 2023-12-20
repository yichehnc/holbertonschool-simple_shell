#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stddef.h>
#include "shell.h"

int _execute_command(char **args)
{

	char *builtin_funcs_list[] = {"cd", "help", "exit"};

	int (*builtin_funcs[])(char **) = {
	    &simple_shell_cd,
	    &simple_shell_help,
	    &simple_shell_exit};

	unsigned int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < sizeof(builtin_funcs_list) / sizeof(char *); i++)
	{
		if (strcmp(args[0], builtin_funcs_list[i]) == 0)
		{
			return ((*builtin_funcs[i])(args));
		}
	}

	return simple_shell_launch(args);
}
