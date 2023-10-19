#include "shell.h"

int _strcmp(char *s1, char *s2);

/**
 * execute_args - checks if a command is a built-in or a process
 * @args: command and flags
 *
 * Return: 1 on success, 0 otherwise
 */

int execute_args(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};

	int (*builtin_func[])(char **) = {
		&own_cd,
		&own_env,
		&own_help,
		&own_exit
	};

	size_t i = 0;

	if (args[0] == NULL)
		return (-1);

	for (; i < (sizeof(builtin_func_list) / sizeof(char *)); i++)
	{
		if (_strcmp(args[0], builtin_func_list[i]) == 0)
			return ((builtin_func[i](args)));
	}

	return (exec_non_builtin(args));
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Psuedo code -
 * compare the ascii int value of each char in s1 & s1 and
 * get the arithemtic difference btn the 2 vals
 * If s1[i] == s2[i] continue with the next itteration of loop.
 * the first instance where s1[i] != s2[i] break from the loop.
 *
 * Return: the value of the difference.
 */

int _strcmp(char *s1, char *s2)
{
	int i, len1, len2, diff;

	len1 = 0;
	while (s1[len1] != '\0')
		len1++;

	len2 = 0;
	while (s2[len2] != '\0')
		len2++;

	for (i = 0; i <= len1 || i <= len2; i++)
	{
		diff = s1[i] - s2[i];
		if (diff == 0)
			continue;
		else if (diff != 0)
			break;
	}

	return (diff);
}
