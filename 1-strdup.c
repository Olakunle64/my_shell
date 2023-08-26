#include "main.h"

/**
 * _strdup - allocate new space in the memory with the copy of str
 * @str: string
 *
 * Description: This function is meant to allocate a new space in the
 * memory and copy the content of the string(str) into the newly
 * allocated space
 * Return: return NULL is str is NULL or return NULL if insufficient
 * memory was available or return a pointer to the duplicated string.
 */

char *_strdup(char *str)
{
	int i, len = 0;
	char *ptr;

	if (!(str))
		return (NULL);
	while (str[len])
	{
		len++;
	}
	len = len + 1;
	ptr = malloc(len * sizeof(char));
	if (ptr)
	{
		for (i = 0; i < len - 1; i++)
		{
			ptr[i] = str[i];
		}
		return (ptr);
		free(ptr);
	}
	return (NULL);
}

