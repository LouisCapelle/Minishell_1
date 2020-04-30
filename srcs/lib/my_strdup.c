/*
** EPITECH PROJECT, 2020
** strdup
** File description:
** my_strdup
*/

#include "my.h"

char *my_strcpy(char *dest, char *src)
{
    int   i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char *str)
{
    char *s;

    if ((s = malloc(my_strlen(str))) == 0)
    {
        return (0);
    }
    my_strcpy(s, str);
    return (s);
}
