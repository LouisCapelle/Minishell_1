/*
** EPITECH PROJECT, 2020
** strcat
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *str, char *buff)
{
    char *dest = malloc(sizeof(char) * my_strlen(str) + my_strlen(buff) + 1);
    int i = 0;
    int k = 0;

    if (str) {
        while (str[i]) {
            dest[i] = str[i];
            i += 1;
        }
    }
    if (buff[k]) {
        while (buff[k]) {
            dest[i++] = buff[k++];
        }
    }
    dest[i] = '\0';
    return dest;
    free(dest);
}