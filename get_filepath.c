#include "shell.h"

char *get_filepath(char *command)
{
	char *path = getenv("PATH");
	char *path_cp;
	char *path_token, *fullpath;
	int command_length = strlen(command) + 2;
	int path_length;
	struct stat st;

	if (path == NULL || strcmp(path, "") == 0)
	{
		return NULL;
	}

	path_cp = strdup(path);
	path_token = strtok(path_cp, ":");

	while (path_token != NULL)
	{
		path_length = strlen(path_token);
		fullpath = malloc(sizeof(char) * (command_length + path_length));

		if (!fullpath)
		{
			perror("Memory allocation failure");
			free(path_cp);
			return NULL;
		}
		snprintf(fullpath, path_length + command_length, "%s/%s", path_token, command);

		if (stat(fullpath, &st) == 0)
		{
			free(path_cp);
			return (fullpath);
		}

		free(fullpath);
		path_token = strtok(NULL, ":");
	}

	free(path_cp);

	if (stat(command, &st) == 0)
	{
		return (strdup(command));
	}
	return (NULL);
}