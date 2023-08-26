#include "main.h"

/**
 * free_buffers - free 4 buffers
 * @buf1: first buffer
 * @buf2: second buffer
 * @buf3: third buffer
 * @buf4: fourth buffer
 *
 * Return: void
 */

void free_buffers(char *buf1, char *buf2, char *buf3, char *buf4)
{
	if (buf1 != NULL)
		free(buf1);
	if (buf2 != NULL)
		free(buf2);
	if (buf3 != NULL)
		free(buf3);
	if (buf4 != NULL)
	{
		free(buf4);
		buf4 = NULL;
	}
}
