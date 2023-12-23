#include "shell.h"

/**
 * get_filepath - Retrieve the full path of a command using the PATH
 * environment.
 * @command: The command for which to find the full path.
 *
 * Description:
 * This function searches for the full path of a command in the PATH
 * directories.
 * It allocates memory for the full path and returns it if found,
 * or NULL if the
 * command is not in any of the specified directories.
 *
 * Parameters:
 * @command: The command for which to find the full path.
 *
 * Return:
 * A dynamically allocated string representing the full path of the command,
 * or NULL if not found or memory allocation fails.
 */
char *get_filepath(char *command)
{
	char *path = getenv("PATH"), *path_cp, *path_token, *fullpath;
	int command_length = strlen(command) + 2, path_length;
	struct stat st;

	if (path == NULL)
		return (NULL);

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
			return (NULL);
		}
		snprintf(fullpath, path_length + command_length, "%s/%s",
				 path_token, command);

		if (stat(fullpath, &st) == 0)
		{
			free(path_cp);
			return (fullpath);
		}

		free(fullpath);
		path_token = strtok(NULL, ":");
	}

	free(path_cp);
	return (NULL);
}
