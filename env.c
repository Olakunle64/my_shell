#include "main.h"

/**
 * env - print the environment variables
 * @cmd: string
 *
 * Return: return 0 if cmd is equal to env or 1 if they
 * are not equal
 */

int env(char *cmd)
{
	char *str;
	int i = 0;

	str = rm_spaces(cmd);
	if (_strcmp(str, "env") == 0)
	{
		while (environ[i])
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
			i++;
		}
		free(str);
		return (0);
	}
	free(str);
	return (1);
}
