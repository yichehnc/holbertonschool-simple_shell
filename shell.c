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

                if (!line)
                {
                        break;
                }

                args = _split_line(line);
                status = _execute_args(args);

                free(line);
                free(args);

                if (status >= 0)
                {
                        exit(status); // Consider using a loop instead of exit() for non-interactive mode
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
