#include "shell.h"

/**
 * split_line - tokenise line read from stdin
 * @line: line read from stdin
 *
 * Return: pointer that points to the new array
 */

char **split_line(char *line)
{
	int bufsize = 64;
	int i = 0;
	char **tokens = NULL;
	char *token;

	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
	{
		perror("allocatio error in split_line: tokens");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += bufsize;
			tokens = realoc(tokens, sizeof(char *) * bufsize);
			if (!tokens)
			{
				perror("reallocation error in split_line: "
						"tokens");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
