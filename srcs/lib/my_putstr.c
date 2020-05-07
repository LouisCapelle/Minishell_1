/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** putstr
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

int my_putstr_noback(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] != '\n')
            my_putchar(str[i]);
        i += 1;
    }
}
