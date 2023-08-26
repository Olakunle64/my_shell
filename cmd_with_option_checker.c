#include "main.h"

/**
 * white_space_flag - check if there are more than one word
 * separated by a space in a string.
 * @buff: string
 *
 * Return: return true if there are more than one word or false
 * there there are no more than one word.
 */

bool white_space_flag(char *buff)
{
	int i = 0;

	while (buff[i] != '\0')
	{
		if (buff[i] == ' ' && buff[i + 1] != ' ' && buff[i + 1] != '\0')
		{
			return (true);
		}
		i++;
	}
	return (false);
}
