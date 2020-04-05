/*
** EPITECH PROJECT, 2020
** my
** File description:
** main
*/

#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#ifndef MY_H_
#define MY_H_

typedef struct shell
{
    char **env;
    char *path_line;
    char **path_parsed;
    char *buf;
    char **buf_array;
    pid_t pid;
}shell_t;

int my_putstr(char *str);

void my_pid(shell_t *control, int a, char **env);

char *my_strcat(char *dest, char *src);

char *my_strstr(char *str, char *to_find);

void my_putchar(char c);

int my_put_nbr(int nb);

int my_strlen(char *str);

char *my_revstr(char *str);

char *my_strcat(char *str, char *buff);

char **my_str_to_word_array(char *str);

int count_path(char *line);

int shell(char **env);

shell_t *init_shell(shell_t *shell, char **env);

int check_args(int ac, char **env);

int my_strcmp(char *s1, char *s2);

int my_strncmp(char *s1, char *s2, int n);

int find_path_line(char **env);

char *get_path_line(char **env);

char **path_to_word_array(char *path_line);

char *my_strndup(char *src, int n);

int *my_strncpy(char *dest, char *src, int n);

char *check_command(void);

void not_found(char *cmd);

int check_builtin(char **buffer);

void not_found(char *cmd);

char *hanled_exec_path(char *path_parsed, char *entry);

char *search_in_path(char *path_line, char **buffer, char **path_parsed);

int exec_command(char **env, char **buffer, shell_t *shell);

int do_builtin(int built, char **env, char **buffer);

int cd(char **buffer, char **env);

char *get_home_path(char **env);

void free_all(char **buf_array);

int get_args(char **args);

int set_env(char **buffer, char **env);

int exec_cmd(char **buffer, char *cmd, char **env);

#endif /* !MY_H_ */
