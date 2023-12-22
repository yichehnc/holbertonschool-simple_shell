#include "shell.h"

const char *get_filename(const char *path)
{
	const char *filename = strrchr(path, '/');
	return (filename != NULL) ? (filename + 1) : path;
}
