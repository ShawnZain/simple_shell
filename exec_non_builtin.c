#include "shell.h"

/**
 * exec_non_builtin - executes non built in commands
 * @args: array of strings after split_line has run
 * Return: 1 on success 0 otherwise
 */

int exec_non_builtin(char *args[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		/* child process */
		if (execvp(args[0], args) == -1)
			perror("error in exec_non_builtin: child process");

		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("error in exec_non_builtin: forking");
	else
	{
		/* parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}
