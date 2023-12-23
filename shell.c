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
        char *line = NULL;
        char **args = NULL;
        int status = 0;
        int exit_loop = 0;

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

                if (line == NULL || strcmp(line, "exit\n") == 0)
                {
                        exit_loop = 1;
                }
                else
                {
                        args = _split_line(line);
                        status = _execute_args(args);
                }

                free(line);
                free(args);

                if (exit_loop)
                {
                        exit(status);
                }
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
