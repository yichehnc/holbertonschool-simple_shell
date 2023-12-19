#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 1024
char *_read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        else
        {
            free(line);
            perror("error while reading line from stdin");
            exit(EXIT_FAILURE);
        }
    }

    return line;
}
