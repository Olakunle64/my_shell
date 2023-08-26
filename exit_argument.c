#include "main.h"

/**
 * handle_builtin - exit when what is inputed is <exit>
 * @cmd: command
 * @argv: shell executable
 * @exit_status: exit status from the main
 *
 * Return: void
 */

int handle_builtin(char *cmd, char *argv, int *exit_status)
{
	char *ptr, **av, *store;
	int i = 0, ret = 0;

	if (white_space_flag(cmd) == true)
	{
		store = strdup(cmd);
		av = tokenize(store);
		if (strcmp(av[0], "exit") == 0)
		{
			i = 0;
			while (av[1][i] != '\0')
			{
				if (!(av[1][i] >= '0' && av[1][i] <= '9'))
				{
					errmsg_exit(argv, av);
					ret = 1;
					break;
				}
				i++;
			}
			ex_sub(cmd, store, av, i);
		}
		free(store);
		free(av[0]);
		free(av[1]);
		free(av);
	}
	else
	{
	ptr = rm_spaces(cmd);
	if (strcmp(ptr, "exit") == 0)
	{
		free_buffers(ptr, cmd, NULL, NULL);
		exit(*exit_status);
	}
	free(ptr);
	}
	return (ret);
}

/**
 * tokenize - tokenize a string
 * @store: string
 *
 * Return: return an integer
 */

char **tokenize(char *store)
{
	int i = 0;
	char *ptr, **av;

	av = malloc(sizeof(*av) * 2);
	if (av == NULL)
		exit(0);
	ptr = strtok(store, " ");
	while (ptr != NULL && i < 2)
	{
		av[i] = malloc(sizeof(char) * strlen(ptr) + 1);
		strcpy(av[i], ptr);
		ptr = strtok(NULL, " ");
		i++;
	}
	return (av);
}

/**
 * ex_sub - the remaining part of handle_builtin func
 * @cmd: string
 * @store: string
 * @av: double pointer
 * @i: integer
 *
 * Return: void
 */

void ex_sub(char *cmd, char *store, char **av, int i)
{
	int num;

	if (av[1][i] == '\0')
	{
		num = atoi(av[1]);
		if (num > 255)
			num = num % 256;
		free_buffers(store, cmd, av[0], av[1]);
		free(av);
		exit(num);
	}
}

/**
 * rm_spaces - handpick all the character of a string
 * @str: string
 *
 * Return: return a string containing all the characters
 */

char *rm_spaces(char *str)
{
	int i = 0, count = 0, j = 0;
	char *ptr;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			count++;
		}
		i++;
	}
	ptr = malloc(sizeof(char) * (count + 1));
	if (ptr == NULL)
		exit(0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			ptr[j] = str[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
