#include "shell.h"

/**
 * main - checks if the function was called
 *
 * Return: success
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
		shell_interactive();
	else
		shell_non_interactive();

	return (0);
}
