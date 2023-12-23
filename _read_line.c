#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 1024

/**
 * _read_line - Read a line from standard input.
 *
 * Description:
 * This function reads a line from standard input using the getline function.
 * It allocates memory for the line and returns it. If an error occurs or
 * the end of file is reached, it returns NULL.
 *
 * Return:
 * A dynamically allocated string containing the read line, or NULL on error
 * or end of file.
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
