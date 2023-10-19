#include "shell.h"

/**
 * read_stream - read a line from stream
 * Return: pointer to the line that has been read
 */

char *read_stream(void)
{
	int bufsize = 1024;
	int index = 0;
	char *line = NULL;
	int character, r;

	line = malloc(sizeof(char) * bufsize);
	if (!line)
	{
		perror("allocation error in read_stream");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		r = read(STDIN_FILENO, character, 1);
		if (character == EOF)
		{
			free(line);
			exit(EXT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[index] = '\0';
			return (line);
		}
		else
			line[index] = character;
		i++;

		if (i >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (!line)
			{
				perror("reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
