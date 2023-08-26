#include "main.h"

/**
 * all_white_spaces - check if all the characters of a string are
 * all white spaces.
 * @str: string
 *
 * Return: return NULL if all are white spaces or the exact string
 * if all are not white spaces.
 */

char *all_white_spaces(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			break;
		}
		i++;
		if (str[i] == '\0')
		{
			return (NULL);
		}
	}
	return (str);
}
