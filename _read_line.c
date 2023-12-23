#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 1024

/**
 * _read_line - Read a line of input from stdin.
 *
 * Return:
 * - On success, returns a dynamically allocated string containing the line.
 * - On failure or EOF, returns NULL.
 */
char *_read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		if (feof(stdin))
		{
			return (NULL);
		}
		else
		{
			perror("error while reading line from stdin");
			return (NULL);
		}
	}

	return (line);
}
