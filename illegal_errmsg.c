#include "main.h"

/**
 * errmsg_exit - compute the error message that is printed to the
 * standard error.
 * @argv: double pointer
 * @exe: the excutable file of the shell
 *
 * Return: void
 */

void errmsg_exit(char *exe, char **argv)
{
	char *str = "Illegal number:";

	write(2, exe, strlen(exe));
	_putchar(':');
	_putchar(' ');
	_putchar('1');
	_putchar(':');
	_putchar(' ');
	write(2, argv[0], strlen(argv[0]));
	_putchar(':');
	_putchar(' ');
	write(2, str, strlen(str));
	_putchar(' ');
	write(2, argv[1], strlen(argv[1]));
	_putchar('\n');
}
