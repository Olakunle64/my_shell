#include "main.h"

/**
 * errmsg - compute the error message that is printed to the
 * standard error.
 * @cmd: the command that does not exist
 * @exe: the excutable file of the shell
 *
 * Return: void
 */

void errmsg(char *cmd, char *exe)
{
	char *str = "not found";

	write(2, exe, _strlen(exe));
	_putchar(':');
	_putchar(' ');
	_putchar('1');
	_putchar(':');
	_putchar(' ');
	write(2, cmd, _strlen(cmd));
	_putchar(':');
	_putchar(' ');
	write(2, str, _strlen(str));
	_putchar('\n');
}
