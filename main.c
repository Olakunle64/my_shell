#include "main.h"

/**
 * main - This program is meant to work just like the sh shell
 * @ac: argument count
 * @argv: argument vector
 *
 * Description: The function will start by displaying a prompt and
 * allowing the user to run commands
 * Return: Always (0) Success.
 */

int main(int ac, char *argv[])
{
	char *prompt, *buf = NULL;
	size_t size_buf = 0;
	ssize_t line_r = 0;
	int exit_status = 0;

	if (ac != 1)
	{
		perror("failed");
		return (0);
	}
	prompt = isatty(STDIN_FILENO) ? "($) " : NULL;
	while (1)
	{
		write(STDOUT_FILENO, prompt ? prompt : NULL, prompt ? 4 : 0);
		line_r = getline(&buf, &size_buf, stdin);
		if (line_r == -1)
		{
			write(STDOUT_FILENO, prompt ? "\n" : NULL, 1);
			free(buf);
			break;
		}
		buf[line_r - 1] = '\0';
		if (*buf == '\0')
			continue;
		if (all_white_spaces(buf) == NULL)
			continue;
		if (env(buf) == 0)
		{
			free(buf);
			buf = NULL;
			continue;
		}
		sub_func(buf, argv[0], &exit_status);
		free(buf);
		buf = NULL;
	}
	if (exit_status != 0)
		exit(exit_status);
	return (0);
}

/**
 * sub_func - This function is the remaining part of the main function
 * @buf: a pointer with allocated memory
 * @argv: a string
 * @exit_status: exit_status
 *
 * Return: void
 */

void sub_func(char *buf, char *argv, int *exit_status)
{
	pid_t pid;
	int status;
	char *handle;

	if (handle_builtin(buf, argv, exit_status) == 1)
	{
		*exit_status = 2;
	}
	else
	{
	handle = handle_path(buf);
	if (handle == NULL)
	{
		errmsg(buf, argv);
		*exit_status = 127;
	}
	else
	{
		pid = fork();
		if (pid == 0)
			execute_all(handle, argv, buf, exit_status);
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				*exit_status = WEXITSTATUS(status);
		}
	}
	free(handle);
	}
}
