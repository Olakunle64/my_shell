#include "main.h"

/**
 * rem_string - store all the characters after the first word
 * of a string with more than word.
 * @str: string
 * Description: note that this function is just a pre-function,
 * the last function that will complete the work of this function
 * is named as f_rem_string.
 *
 * Return: return a pointer to the new string.
 */

char *rem_string(char *str)
{
	int i = 0, count = 0, j, k;
	char *ptr;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			j = i;
			while (str[i] != '\0')
			{
				count++;
				i++;
			}
			break;
		}
		i++;
	}
	k = 0;
	ptr = malloc(sizeof(char) * (count + 1));
	if (ptr == NULL)
		exit(1);
	while (j < _strlen(str))
	{
		ptr[k] = str[j];
		j++;
		k++;
	}
	ptr[k] = '\0';
	return (ptr);
}

/**
 * f_rem_string - This function is meant to remove the
 * remaining word of a string apart from the first word.
 * @str: string
 *
 * Return: return the remaining word as a string or NULL if
 * it failed.
 */

char *f_rem_string(char *str)
{
	char *ptr;

	while (*str != '\0')
	{
		if (*str != ' ')
		{
			ptr = rem_string(str);
			return (ptr);
		}
		str++;
	}
	return (NULL);
}
