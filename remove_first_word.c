#include "main.h"

/**
 * rm_f_word - This function is meant to remove the
 * first word of a string
 * @s: string
 *
 * Return: return a pointer to the first word
 */

char *rm_f_word(char *s)
{
	int i = 0, j = 0;
	char *ptr;

	while (s[i] != ' ' && s[i] != '\0')
	{
		i++;
	}
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
	{
		perror("Memory Allocation Failed\n");
		exit(1);
	}
	while (j < i)
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

/**
 * f_rm_f_word - remove the first word of a string excluding
 * a white space(s)
 * @s: string
 *
 * Return: return a pointer to the first word
 */

char *f_rm_f_word(char *s)
{
	char *ptr;

	while (*s != '\0')
	{
		if (*s != ' ')
		{
			ptr = rm_f_word(s);
			return (ptr);
		}
		s++;
	}
	return (NULL);
}
