/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        i += 1;
    }
    if (s1[i] != '\0' && s2[i] != '\0')
        return 1;
    return 0;
}

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && i != n) {
        i += 1;
    }
    if (i != n)
        return -1;
    else
        return 0;
}