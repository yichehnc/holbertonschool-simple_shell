#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "shell.h"

void run_non_interactive(void)
{
        /*
        Read: Read command from standard input
        Parse: Separate command into a program and arguments
        Execute: Run the parsed command
        */
        char *line;
        char **args;
        int status = -1;

        do
        {
                line = _read_stream();
                args = _split_line(line);
                status = _execute_args(args);

                free(line);
                free(args);

                if (status >= 0)
                {
                        exit(status);
                }
        } while (status == -1);
}

void run_interactive(void)
{
        /*
        Read: Read command from standard input
        Parse: Separate command into a program and arguments
        Execute: Run the parsed command
        */
        char *line;
        char **args;
        int status = -1;

        do
        {

                printf("$ ");
                line = _read_line();

                if (!(*line))
                        break;
                args = _split_line(line);
                status = _execute_args(args);
                free(line);
                free(args);

                if (status >= 0)
                {
                        exit(status);
                }
        } while (status == -1);
}

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
