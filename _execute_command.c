#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stddef.h>
#include "shell.h"

int (*builtin_func[])(char **) = {
    &simple_shell_cd,
    &simple_shell_help,
    &simple_shell_exit};

int _execute_command(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < simple_shell_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_arr[i]) == 0)
		{
			return (*builtin_func[i])(args);
		}
	}

	return simple_shell_launch(args);
}
