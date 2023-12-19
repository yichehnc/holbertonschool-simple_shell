#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 1024
char *_read_line(void)
{
    int bufsize = BUFSIZE;
    int position = 0;
    int c;
    char *buffer = malloc(sizeof(char) * bufsize);
    if (!buffer)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        c = getchar();
        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
        position++;
        if (position >= bufsize)
        {
            bufsize += BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer)
            {
                fprintf(stderr, "Memory allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}
