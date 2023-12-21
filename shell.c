#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

void run_non_interactive(void)
{
        ssize_t bytes_read;
        int i, status = -1, command_count = 0;
        char *commands[MAX_COMMAND_LENGTH], *token, **args, line[MAX_COMMAND_LENGTH];

        /* Read the input from standard input */
        if ((bytes_read = read(STDIN_FILENO, line, MAX_COMMAND_LENGTH)) == -1)
        {
                perror("Error reading line");
                exit(EXIT_FAILURE);
        }

        line[bytes_read - 1] = '\0';

        /* Tokenize the line into commands */
        token = strtok(line, "\n");

        while (token != NULL)
        {
                commands[command_count++] = token;
                token = strtok(NULL, "\n");
        }

        /* Handle each command contained in the line input*/
        for (i = 0; i < command_count; ++i)
        {
                /* Tokenize the command into arguments*/
                args = _split_line(commands[i]);
                status = _execute_args(args);
                /*free(line);*/
                free(args);

                if (status >= 0)
                {
                        free(args);
                        exit(status);
                }
        }
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
