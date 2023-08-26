#include "main.h"

/**
 * malloc_ret - check for malloc return
 * @ptr: pointer to the memory allocated
 *
 * Return: void
 */

void malloc_ret(char *ptr)
{
	if (ptr == NULL)
	{
		printf("Memory Allocation Failed\n");
		exit(0);
	}
}
