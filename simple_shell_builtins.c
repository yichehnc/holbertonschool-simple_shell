#include <stdio.h>
#include "shell.h"

char *builtin_arr[] = {"cd", "help", "exit"};

int simple_shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "simple_shell: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("simple_shell");
		}
	}
	return (1);
}

int simple_shell_help(__attribute__((unused)) char **args)
{
	int i;
	printf("Simple Shell\n");
	printf("Type program names and arguments, and hit enter\n");
	printf("The following are built in:\n");

	for (i = 0; i < simple_shell_num_builtins(); i++)
	{
		printf("  %s\n", builtin_arr[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return (1);
}

int simple_shell_exit(__attribute__((unused)) char **args)
{
	return (0);
}

int simple_shell_num_builtins()
{
	return sizeof(builtin_arr) / sizeof(char *);
}
