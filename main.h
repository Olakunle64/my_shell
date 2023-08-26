#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;
void execute_all(char *buff, char *av, char *buf, int *exit_status);
char *_stat(char *name, char *ptr);
char *_getenv(const char *name);
char *check_exist(char *name);
char *_stat(char *name, char *path);
char *handle_path(char *name);
bool white_space_flag(char *buff);
int check_for_slash(char *str);
char *rem_string(char *str);
char *rm_f_word(char *s);
char *f_rem_string(char *str);
char *f_rm_f_word(char *s);
char *all_white_spaces(char *str);
void errmsg(char *cmd, char *exe);
int _putchar(char c);
char *rm_spaces(char *str);
int handle_builtin(char *cmd, char *argv, int *exit_status);
int env(char *cmd);
void sub_func(char *buf, char *argv, int *exit_status);
void malloc_ret(char *ptr);
char *_stat_sub(char *ptr, char *rem, int checker);
void free_buffers(char *buf1, char *buf2, char *buf3, char *buf4);
void errmsg_exit(char *exe, char **argv);
void ex_sub(char *cmd, char *store, char **av, int i);
char **tokenize(char *store);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);

#endif /* MAIN_H */
