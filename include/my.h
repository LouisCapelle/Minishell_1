/*
** EPITECH PROJECT, 2020
** my
** File description:
** main
*/

#include <stdarg.h>

#ifndef MY_H_
#define MY_H_

typedef struct shell
{
    char **path;
    char **env;
    char **args;
    int fd;
    char buffer;
}shell_t;

int my_putstr(char *str);

void my_putchar(char c);

int my_put_nbr(int nb);

int my_strlen(char *str);

char *my_revstr(char *str);

char **my_str_to_word_array(char *str);

#endif /* !MY_H_ */
