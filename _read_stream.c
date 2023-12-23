#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 1024

/**
 * _read_stream - Read a line from standard input using dynamic memory
 * allocation.
 *
 * Description:
 * This function reads characters from standard input and dynamically allocates
 * memory to store the line. The buffer size starts at BUFSIZE and grows if
 * needed.
 * It returns the read line as a dynamically allocated string or NULL on error
 * or end of file.
 *
 * Return:
 * A dynamically allocated string containing the read line, or NULL on error
 * or end of file.
 */
char *_read_stream()
{
	int bufsize = BUFSIZE, i = 0, ch;
	char *line = malloc(bufsize * sizeof(char));

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
