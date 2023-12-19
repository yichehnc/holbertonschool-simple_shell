#include <stdio.h>
#include "shell.h"

char *builtin_func_list[] = {"cd", "help", "exit"};

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
	long unsigned int i;

	printf("Simple Shell\n");
	printf("Type program names and arguments, and hit enter\n");
	printf("The following are built in:\n");

	for (i = 0; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		printf("  %s\n", builtin_func_list[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return (1);
}

int simple_shell_exit(__attribute__((unused)) char **args)
{
	return (0);
}
