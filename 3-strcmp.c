#include "main.h"

/**
 * _strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Description: This function is meant to compare two strings
 * Return: return the ASCII difference between
 * the corresponding unequal character in s1 and s2
 */

int _strcmp(char *s1, char *s2)
{
	int i, sub, len1;

	len1 = _strlen(s1);
	for (i = 0; i < len1 && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			sub = s1[i] - s2[i];
			return (sub);
		}
		else
		{
			continue;
		}
	}
	return (0);
}
