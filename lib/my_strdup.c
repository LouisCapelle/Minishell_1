/*
** EPITECH PROJECT, 2020
** strdup
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != 0) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char *str)
{
    char *s;

    if ((s = malloc(sizeof(char) * (my_strlen(str) + 2))) == 0)
    {
        return (0);
    }
    my_strcpy(s, str);
    return (s);
}
