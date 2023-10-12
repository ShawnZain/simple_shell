#include "shell.h"

/**
 * shell_interactive - UNIX command line interpreter
 *
 * Return: void
 */
void shell_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		write(STDOUT_FILENO, "(S) ", sizeof(char) * 4);
		line = read_line(); /* read line from stdin */
		args = split_line(line); /* tokenization */
		status = execute_args(args);

		/* avoid mem leaks */
		free(line);
		free(args);

		/* exit with status */
		if (status >= 0)
			exit(status);
	} while (status == -1);
}
