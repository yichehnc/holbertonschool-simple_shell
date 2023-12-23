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
		free(line);
		if (feof(stdin))
		{
			return NULL;
		}
		else
		{
			perror("error while reading line from stdin");
			return NULL;
		}
	}

	return line;
}
