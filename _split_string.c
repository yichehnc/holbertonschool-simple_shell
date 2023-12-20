#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORDS_BUFSIZE 64
#define WORDS_DELIM " \t\n\a"
/**
 * split_text - Split a string into tokens based on delimiters.
 * @line: The input string to be split.
 *
 * Return: An array of tokens (words) obtained from the input string.
 *         The array is terminated by a NULL pointer.
 */
char **_split_string(char *line)
{
        int bufsize = WORDS_BUFSIZE, position = 0;
        char **tokens = malloc(bufsize * sizeof(char *));
        char *token;
        if (!tokens)
        {
                fprintf(stderr, "_split_string: Memory allocation failure - tokens\n");
                exit(EXIT_FAILURE);
        }
        token = strtok(line, WORDS_DELIM);
        while (token != NULL)
        {
                if (token[0] == '#') /*to handle comments*/
                        break;

                tokens[position] = token;
                position++;
                if (position >= bufsize)
                {
                        bufsize += WORDS_BUFSIZE;
                        tokens = realloc(tokens, bufsize * sizeof(char *));
                        if (tokens != NULL)
                        {
                                fprintf(stderr, "_split_string: Memory allocation failure - tokens\n");
                                exit(EXIT_FAILURE);
                        }
                }
                token = strtok(NULL, WORDS_DELIM);
        }
        tokens[position] = (char *)NULL;
        return (tokens);
}
