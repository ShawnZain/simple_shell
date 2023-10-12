#include "shell.h"

/**
 * read_line - reads from stdin
 * Return: pointer to a buffer that holds what has been read
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("Error while reading line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
