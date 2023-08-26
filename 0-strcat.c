#include "main.h"

/**
 * _strcat - append src string to dest string
 * @dest: destination string
 * @src: source string
 *
 * Description: append src string to dest string overwriting the terminating
 * null byte at the end of dest, and then adds a terminating null byte.
 * Return: return a pointer to resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int len1 = 0;
	int len2 = 0;
	int i = 0;

	while (dest[len1] != '\0')
	{
		len1++;
	}
	while (src[len2] != '\0')
	{
		len2++;
	}
	for (i = 0; i < len2; i++)
	{
		dest[len1 + i] = src[i];
	}
	dest[len1 + i] = '\0';
	return (dest);
}
