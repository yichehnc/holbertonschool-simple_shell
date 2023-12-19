#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
void shell_loop()
{
        /*
        Read: Read command from standard input
        Parse: Separate command into a program and arguments
        Execute: Run the parsed command
        */
        char *line;
        char **commands;
        int status;
        do
        {
                printf("$ ");
                line = _read_line();
                if (!(*line))
                        break;
                commands = _split_string(line);
                status = _execute_command(commands);
                free(line);
                free(commands);
        } while (status);
}
int main(void)
{
        shell_loop();
        return (EXIT_SUCCESS);
}
