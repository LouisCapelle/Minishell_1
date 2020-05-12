/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

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
#include <stdbool.h>

typedef struct shell
{
    char **env;
    char *path_line;
    char **path_parsed;
    char *cmd;
    char **cmd_parsed;
    pid_t pid;
}shell_t;


int minishell(char **env);

int my_putstr(char *str);

char *my_strcat(char *dest, char *src);

char *my_strstr(char *str, char *to_find);

void my_putchar(char c);

int my_put_nbr(int nb);

int my_strlen(char *str);

char *my_strncpy(char *dest, char const *src, int nb);

char *my_strndup(char const *src, int n);

char *my_revstr(char *str);

char *my_strcat(char *str, char *buff);

int my_putstr_noback(char *str);

int my_strncmp(char *s1, char *s2, int n);

char *my_strdup(char *str);

char **my_str_to_word_array(char *str);

char *get_env_line(char *line, char **env);

void free_all(char **buf_array);

char **separator_to_word_array(char *separator, char carac);

int get_command(shell_t *shell);

int find_line(char *line, char **env);

int check_spaces(char *cmd);

int init_command(shell_t *shell, char *cmd);

void my_exit(int status);

bool check_builtins(char *cmd);

int do_builtin(char **cmd, shell_t *shell);

int do_cd(char **buffer, char **env);

char *get_cmd_path(char *cmd, shell_t *shell);

bool check_local(char *cmd);

int command_not_found(char *cmd);

int exec_error(char *cmd);

int get_segfault(int segfault);

int exec_local(char **cmd, shell_t *shell);

int prepare_command(shell_t *shell, char **parsed_cmd);

int exec_command(char *cmd, char **buffer, char **env);

int get_args(char **args);

int my_setenv(char **buffer, shell_t *shell);

int check_creating_env_var(char **buffer, int args);

int my_unsetenv(shell_t *shell, char **buffer);

#endif /* !MY_H_ */
