#include "main.h"

/**
 * check_for_slash - This function is meant to check if a file
 * already contains its full path
 * @str: filename
 *
 * Return: return 0 if it already has its full path
 * and also exist and executable or 2 if it
 * has no complete path or -1 if str is '\0'
 */

int check_for_slash(char *str)
{
	struct stat status;
	char *s = f_rm_f_word(str);
	int flag;

	while (s[0] != '\0')
	{
		if (s[0] == '/' || s[0] == '.')
		{
			flag = stat(s, &status);
			if (flag == 0 && access(s, X_OK) == 0)
			{
				free(s);
				return (0);
			}
			else
			{
				free(s);
				return (-1);
			}
		}
		else
		{
			free(s);
			return (2);
		}
	}
	return (-1);
}
