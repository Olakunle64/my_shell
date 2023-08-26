#include "main.h"

/**
 * _putchar - writes the character c to stderr
 * @c: the character to print
 *
 * Return: On Success 1.
 * On error, -1 is returned, and err no is set appropriately.
 */
int _putchar(char c)
{
	return (write(2, &c, 1));
}
