#include "shell.h"

/**
 * get_filepath - Get the full path of a command based on the PATH
 * environment variable.
 * @command: The command for which to find the full path.
 *
 * Return:
 * - On success, returns a dynamically allocated string containing the
 * full path.
 * - On failure or if the command is not found, returns NULL.
 */
char *get_filepath(char *command)
{
	char *path_env = NULL;
	char *filepath = NULL;
	char *path_dir = NULL;
	char *potential_path = NULL;

	/*Check if command contains a path*/
	if (strchr(command, '/') != NULL)
	{
		/*Use command as filepath if it exists*/
		if (access(command, X_OK) == 0)
		{
			filepath = strdup(command);
		}
	}
	else
	{
		/*Search for command in PATH directories*/
		path_env = getenv("PATH");
		if (path_env)
		{
			path_dir = strtok(path_env, ":");
			while (path_dir)
			{
				potential_path = malloc(strlen(path_dir) + strlen(command) + 2);
				strcpy(potential_path, path_dir);
				strcat(potential_path, "/");
				strcat(potential_path, command);
				if (access(potential_path, X_OK) == 0)
				{
					filepath = potential_path;
					break;
				}
				free(potential_path);
				path_dir = strtok(NULL, ":");
			}
		}
	}

	return (filepath);
}
