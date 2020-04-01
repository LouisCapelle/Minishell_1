/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int	n = 0;
    int	len = my_strlen(str) - 1;
    char op;

    while (n < len) {
        op = str[n];
        str[n] = str[len];
        str[len] = op;
        n++;
        len--;
    }
    return (str);
}