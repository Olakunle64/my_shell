#include "main.h"

/**
 * execute_all - This function is meant to execute all commands
 * with option or without options
 * @buff: command name
 * @av: second string
 * @buf: third buffer
 * @exit_status: exit status
 *
 * Return: void
 */

void execute_all(char *buff, char *av, char *buf, int *exit_status)
{
	int val;
	char *ptr;
	char **argv;
	char *store;
	int count = 0, i = 0;

	store = malloc(sizeof(char) * _strlen(buff) + 1);
	malloc_ret(store);
	_strcpy(store, buff);
	ptr = strtok(buff, " ");
	while (ptr != NULL)
	{
		count++;
		ptr = strtok(NULL, " ");
	}
	argv = malloc((count + 1) * sizeof(*argv));
	malloc_ret((char *)argv);
	ptr = strtok(store, " ");
	while (ptr != NULL)
	{
		argv[i] = ptr;
		ptr = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
	val = execve(argv[0], argv, NULL);
	if (val == -1)
	{
		perror(av);
		free_buffers(store, (char *)argv, buff, buf);
		*exit_status = 2;
		exit(*exit_status);
	}
	free(store);
	free(argv);
}
