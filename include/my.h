/*
** EPITECH PROJECT, 2020
** my
** File description:
** main
*/

#include <stdarg.h>
#include <sys/types.h>

#ifndef MY_H_
#define MY_H_

typedef struct shell
{
    char **path;
    char **env;
    char **array;
    char **args;
    int fd;
    char buffer;
    int status;
    char *str_cat;
    pid_t pid;
}shell_t;

typedef struct var
{
    int i;
    int a;
    int b;
}t_var;

int my_putstr(char *str);

char **my_str_to_wordtab(char *str, char carac);

void my_pid(shell_t *control, int a, char **env);

char *my_strcat(char *dest, char *src);

int my_exec(shell_t *control, char **env);

void built_in_cd(shell_t *shell);

char *my_strstr(char *str, char *to_find);

void my_putchar(char c);

int my_put_nbr(int nb);

int my_strlen(char *str);

char *my_revstr(char *str);

char **my_str_to_word_array(char *str);

#endif /* !MY_H_ */
