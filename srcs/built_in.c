/*
** EPITECH PROJECT, 2020
** built_in
** File description:
** built_in
*/

#include "my.h"
#include <stdlib.h>

void check_exit(shell_t *shell)
{
    if (my_strcmp(shell->buf_array[0], "exit") == 0) {
        my_putstr("exit\n");
        free(shell);
        exit(0);
    }
}

int check_builtin(shell_t *shell)
{
    check_exit(shell);
    return 0;
}