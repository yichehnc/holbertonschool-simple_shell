#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 1024;

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
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		ch = getchar(); /* read first char from stream */
		if (ch == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (ch == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
		{
			line[i] = ch;
		}
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
