#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 1024

/**
 * _read_stream - Read a line of input from the standard input stream.
 *
 * Return:
 * - On success, returns a dynamically allocated string containing the input
 * line.
 * - On failure, returns NULL.
 */
char *_read_stream()
{
	int bufsize, i, ch;
	char *line;

	bufsize = BUFSIZE;
	i = 0;
	line = malloc(bufsize * sizeof(char));

	if (line == NULL)
	{
		perror("memory allocation failed in _read_stream\n");
		return (NULL);
	}

	while ((ch = getchar()) != EOF)
	{
		line[i++] = ch;

		if (ch == '\n')
		{
			line[i] = '\0';
			return (line);
		}

		if (i >= bufsize)
		{
			bufsize += bufsize / 2;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				return (NULL);
			}
		}
	}

	free(line);
	return (NULL);
}
