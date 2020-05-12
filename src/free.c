/*
** EPITECH PROJECT, 2020
** free
** File description:
** free
*/

#include "my.h"

void free_struct(shell_t *shell)
{
    free_word_array(shell->env);
    free_word_array(shell->path_parsed);
    free(shell->path_line);
}

void free_word_array(char **buf_array)
{
    int i = 0;

    while (buf_array[i] != NULL) {
        free(buf_array[i]);
        i += 1;
    }
    free(buf_array);
}