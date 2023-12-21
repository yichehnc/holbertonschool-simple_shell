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

	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ')
			continue;

		line[i] = ch;
		i++;

		if (i >= bufsize)
		{
			bufsize += BUFSIZE;
			line = realloc(line, bufsize);

			if (line == NULL)
			{
				perror("Memory reallocation failure in _read_steam");
				exit(EXIT_FAILURE);
			}
		}
	}

	line[i] = '\0';
	return line;
}