/*
** EPITECH PROJECT, 2020
** free
** File description:
** free
*/

#include "my.h"

void **free_all(char **buf_array)
{
    int i = 0;

    while (buf_array[i] != NULL) {
        free(buf_array[i]);
        i += 1;
    }
    free(buf_array);
    return NULL;
}

