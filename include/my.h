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

int my_putstr(char *str);

void my_pid(shell_t *control, int a, char **env);

char *my_strcat(char *dest, char *src);

char *my_strstr(char *str, char *to_find);

void my_putchar(char c);

int my_put_nbr(int nb);

int my_strlen(char *str);

char *my_revstr(char *str);

char **my_str_to_word_array(char *str);

int shell(char **env);

#endif /* !MY_H_ */
