#include "shell.h"

/**
 * shell_cd - Change current working directory.
 * @args: Array of strings representing the command and its arguments.
 *
 * Description:
 * Changes current directory based on provided arguments.
 * Prints error to stderr if no argument or on permission issues.
 *
 * Parameters:
 * @args: Array of strings representing the command and its arguments.
 *
 * Return:
 * Always returns 1, indicating execution status.
 */
int shell_cd(char **args)
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

/**
 * shell_help - Display Simple Shell info and built-in commands.
 * @args: Unused parameter.
 *
 * Description:
 * Displays Simple Shell info, usage, and list of built-in commands.
 *
 * Parameters:
 * @args: Unused parameter.
 *
 * Return:
 * Always returns 1.
 */
int shell_help(__attribute__((unused)) char **args)
{
	unsigned long int i;
	char *builtin_func_list[] = {"cd", "help", "exit"};

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

/**
 * shell_exit - Exit shell with specified exit status.
 * @args: Array of strings representing the command and its arguments.
 *
 * Description:
 * Exits shell with user-specified exit status or default 0.
 *
 * Parameters:
 * @args: Array of strings representing the command and its arguments.
 *
 * Return:
 * Specified exit status or 0 if no argument is provided.
 */
int shell_exit(__attribute__((unused)) char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}

	return (0);
}

/**
 * shell_env - Print current environment variables.
 * @args: Array of strings representing the command and its arguments (unused).
 *
 * Description:
 * Prints current environment variables to stdout.
 * Iterates through `environ` array, printing each variable on a new line.
 *
 * Parameters:
 * @args: Array of strings representing the command and its arguments (unused).
 *
 * Return:
 * Always returns 0, indicating execution status.
 */
int shell_env(__attribute__((unused)) char **args)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}

	return (0);
}
