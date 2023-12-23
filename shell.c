#include "shell.h"

/**
 * free_args - Free the memory allocated for an array of strings.
 * @args: The array of strings to be freed.
 *
 * Description:
 * This function takes an array of strings (char **) and frees the memory
 * allocated for each string and the array itself. It assumes that the
 * array is terminated with a NULL pointer.
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/**
 * run_interactive - Run the shell in interactive mode.
 *
 * Description:
 * This function runs the shell in interactive mode. It prompts the user
 * with "$ ", reads commands from the standard input, and executes them.
 * The shell continues running until the user enters the "exit" command.
 */
void run_interactive(void)
{
	run_shell(1);
}

/**
 * run_non_interactive - Run the shell in non-interactive mode.
 *
 * Description:
 * This function runs the shell in non-interactive mode. It reads commands
 * from a stream (e.g., file or pipeline) and executes them. The shell exits
 * when it encounters the "exit" command or reaches the end of the input.
 */
void run_non_interactive(void)
{
	run_shell(0);
}

/**
 * run_shell - Run the shell in either interactive or non-interactive mode.
 * @interactive: A flag indicating whether to run in interactive mode (1) or
 *                non-interactive mode (0).
 *
 * Description:
 * This function is the core of the shell. It takes a flag to determine the
 * mode (interactive or non-interactive) and executes the corresponding logic.
 * In interactive mode, it prompts the user, reads commands, and executes them
 * until the "exit" command is entered. In non-interactive mode, it reads
 * commands from a stream and executes them.
 */
void run_shell(int interactive)
{
	char *line = NULL, **args = NULL;
	int status = 0, exit_loop = 0, i;

	while (1)
	{
		if (interactive)
		{
			printf("$ ");
			line = _read_line();
		}
		else
		{
			line = _read_stream();
		}

		if (line == NULL || strcmp(line, "exit\n") == 0)
		{
			exit_loop = 1;
		}
		else
		{
			args = _split_line(line);
			if (args[0] == NULL)
			{
				free_args(args);
			}
			else
			{
				status = _execute_args(args);
				free_args(args);
			}
		}

		free(line);

		if (exit_loop)
		{
			exit(status);
		}
	}
}

/**
 * main - Entry point for the shell program.
 *
 * Description:
 * The main function checks if the shell is running in an interactive
 * environment. If so, it runs the shell in interactive mode; otherwise,
 * it runs the shell in non-interactive mode.
 *
 * Return:
 * Returns EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		run_interactive();
	}
	else
	{
		run_non_interactive();
	}
	return (EXIT_SUCCESS);
}
