#include "shell.h"

/**
 * run_interactive - Run the shell in interactive mode.
 *
 * Description:
 * This function is responsible for running the shell in interactive mode,
 * which means it operates with user interaction. It calls the run_shell
 * function with the argument '1' to indicate interactive mode.
 *
 * Return: void
 */
void run_interactive(void)
{
	run_shell(1);
}

/**
 * run_non_interactive - Run the shell in non-interactive mode.
 *
 * Description:
 * This function is responsible for running the shell in non-interactive mode,
 * which means it operates without user interaction. It calls the run_shell
 * function with the argument '0' to indicate non-interactive mode.
 *
 * Return: void
 */
void run_non_interactive(void)
{
	run_shell(0);
}

/**
 * run_shell - Run the shell in either interactive or non-interactive mode.
 * @interactive: An integer indicating the mode
 * (1 for interactive, 0 for non-interactive).
 *
 * Description:
 * This function controls the execution of the shell. It operates in a loop,
 *  reading input
 * either from the user (interactive mode) or from a stream
 * (non-interactive mode).
 * It processes the input, executes commands, and continues until the user e
 * nters "exit" or * an EOF is encountered in non-interactive mode.
 * The function utilizes  * helper functions  * like _read_line, _read_stream,
 * _split_line, and _execute_args for various
 * tasks.
 *
 * Parameters:
 * @interactive: An integer indicating the mode
 * (1 for interactive, 0 for non-interactive).
 *
 * Return: void
 */
void run_shell(int interactive)
{
	char *line = NULL;
	char **args = NULL;
	int status = 0;
	int exit_loop = 0;

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

		if (line == NULL)
		{
			status = 0;
			exit_loop = 1;
		}
		else if (strcmp(line, "exit\n") == 0)
		{
			exit_loop = 1;
		}
		else
		{
			args = _split_line(line);
			if (args == NULL)
			{
				free(line);
				continue;
			}
			status = _execute_args(args);
			free(args);
		}

		free(line);

		if (exit_loop)
		{
			exit(status);
		}
	}
}

/**
 * main - Entry point for the simple shell program.
 *
 * Description:
 * The main function serves as the entry point for the simple shell program.
 * It checks whether the standard input is associated with a terminal
 * (interactive mode).
 * If true, it calls the run_interactive function; otherwise, it calls
 * run_non_interactive.
 * The function returns EXIT_SUCCESS upon successful completion.
 *
 * Return: EXIT_SUCCESS upon successful completion.
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
