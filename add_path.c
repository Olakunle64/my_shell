#include "main.h"

/**
 * _getenv - write a function that get an enviroment variable
 * @name: name of the variable
 *
 * Return: return the address to the value string
 */

char *_getenv(const char *name)
{
	int i = 0, j = 0;
	int len = strlen(name);

	while (environ[i])
	{
		j = 0;
		while (environ[i][j] != '=')
		{
			if (name[j] == environ[i][j])
			{
				j++;
			}
			else
				break;
			j++;
		}
		if (j == len && environ[i][j] == '=')
			return (environ[i] + j + 1);
		i++;
	}
	return (NULL);
}

/**
 * check_exist - split path into directories and use another
 * function to check if the file name matches any of the
 * directories splitted
 * @name: file name
 *
 * Return: return a pointer to the full pathname of the file
 */

char *check_exist(char *name)
{
	int i = 0, j = 0, k = 0, m;
	char *ptr, *fullpath, *str;

	str = _getenv("PATH");
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		j = i;
		m = 0;
		while (str[i] != ':' && str[i] != '\0')
		{
			m++;
			i++;
		}
		ptr = malloc(sizeof(char) * (m + 2));
		malloc_ret(ptr);
		m = 0;
		k = 0;
		while (j < i)
		{
			ptr[k] = str[j];
			j++;
			k++;
		}
		ptr[k] = '/';
		ptr[k + 1] = '\0';
		fullpath = _stat(name, ptr);
		if (fullpath != NULL)
		{
			free(ptr);
			return (fullpath);
		}
		free(ptr);
		if (str[i] == ':')
			i++;
	}
	return (NULL);
}

/**
 * _stat - check if a file exit in a directory
 * @name: file name
 * @path: path of the file
 *
 * Return: return a pointer to the full path name of the file
 * if the file exist or NULL if it doest not exist.
 */

char *_stat(char *name, char *path)
{
	char *ptr, *rem;
	char *store = name;
	int checker =  0;

	if (white_space_flag(name) == true)
	{
		rem = f_rem_string(name);
		checker = 2;
		store = f_rm_f_word(name);
		if (store == NULL)
		{
			free(rem);
			exit(0);
		}
	}
	ptr = malloc((strlen(path) + strlen(store) + 1) * sizeof(char));
	if (ptr == NULL)
	{
		if (checker > 0)
		{
			free(rem);
			free(store);
		}
		exit(0);
	}
	strcpy(ptr, path);
	ptr[strlen(path)] = '\0';
	strcat(ptr, store);
	if (checker > 0)
		free(store);
	return (_stat_sub(ptr, rem, checker));
}

/**
 * _stat_sub - This function is the remaining function
 * of the _stat function
 * @ptr: a string
 * @rem: a string
 * @checker: an integer
 *
 * Return: a pointer.
 */
char *_stat_sub(char *ptr, char *rem, int checker)
{
	char *final_string;
	struct stat status;

	if (stat(ptr, &status) == 0)
	{
		if (checker > 0)
		{
		final_string = malloc(sizeof(char) * (strlen(rem) + strlen(ptr) + 1));
		if (final_string == NULL)
		{
			free(ptr);
			free(rem);
			exit(0);
		}
		strcpy(final_string, ptr);
		final_string[strlen(ptr)] = '\0';
		strcat(final_string, rem);
		free(rem);
		free(ptr);
		return (final_string);
		}
		else
			return (ptr);

	}
	else
	{
		if (checker > 0)
			free(rem);
		free(ptr);
		return (NULL);
	}
}

/**
 * handle_path - This function is meant to add the full path to
 * a file it doesn't contains the full path.
 * @name: file name
 *
 * Return: return the full pathname of the file or NULL if the file name
 * doesn't exist at all
 */

char *handle_path(char *name)
{
	char *ptr;

	if (check_for_slash(name) == 0)
	{
		ptr = strdup(name);
		if (ptr != NULL)
			return (ptr);
	}
	if (check_for_slash(name) == -1)
	{
		return (NULL);
	}
	ptr = check_exist(name);
	if (ptr == NULL)
	{
		return (NULL);
	}
	return (ptr);
}
