#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char *findFileInPath(const char *filename)
{
	size_t fullpath_len;
	char *fullpath;
	char *path = getenv("PATH");
	char *token = strtok(path, ":");
	struct stat st;

	while (token != NULL)
	{
		/* Construct the full path by concatenating the directory and filename */
		fullpath_len = strlen(token) + strlen("/") + strlen(filename) + 1;
		fullpath = (char *)malloc(fullpath_len);

		if (fullpath == NULL)
		{
			perror("Memory allocation failure");
			exit(EXIT_FAILURE);
		}

		sprintf(fullpath, "%s/%s", token, filename);

		/* Check if the file exists */
		if (stat(fullpath, &st) == 0)
		{
			/* If the file exists, return the full path */
			return fullpath;
		}

		free(fullpath); /* Free memory if the file doesn't exist in this directory */

		token = strtok(NULL, ":");
	}

	/* Return NULL if the file is not found in any directory */
	return NULL;
}