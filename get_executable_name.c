#include "shell.h"

/**
 * get_filename - Extract the filename from a given path.
 * @path: A string representing the path from which to extract the filename.
 *
 * Description:
 * This function takes a string @path representing a file path and extracts
 * the filename  * from it. The filename is determined by locating the last
 * occurrence of the '/' character  * in the path. If found, the function
 * returns a pointer to the character immediately following  * the last '/',
 * which represents the filename. If no '/' is found, the entire path is
 * considered  * to be the filename, and a pointer to the original path is
 * returned.
 *
 * Parameters:
 * @path: A string representing the path from which to extract the filename.
 *
 * Return:
 * The function returns a pointer to the extracted filename.
 * If the path is NULL,  * the return  * value is NULL. If the path contains
 * no '/', the return value is  * the same as the input path.
 */
const char *get_filename(const char *path)
{
	const char *filename = strrchr(path, '/');

	return ((filename != NULL) ? (filename + 1) : path);
}
