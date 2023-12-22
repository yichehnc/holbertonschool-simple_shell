#include "shell.h"

void run_interactive()
{
        run_shell(1);
}

void run_non_interactive()
{
        run_shell(0);
}

void run_shell(int interactive)
{
        char *line;
        char **args;
        int status;

        do
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
                        break;
                }

                args = _split_line(line);
                status = _execute_args(args);

                if (status == EXIT_SUCCESS && strcmp(args[0], "exit") == 0)
                {
                        free(line);
                        free(args);
                        exit(EXIT_SUCCESS);
                }
                /*else if (status == EXIT_FAILURE)
                {
                        fprintf(stderr, "Command execution failed\n");
                }*/
                free(line);
                free(args);
        } while (1);
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
