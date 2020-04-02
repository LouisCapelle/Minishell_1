/*
** EPITECH PROJECT, 2020
** built_in
** File description:
** built_in
*/

#include "my.h"
#include <stdlib.h>

void not_found(char *cmd)
{
    my_putstr(cmd);
    my_putstr(": Command not found.\n");
}

int check_exit(shell_t *shell)
{
    if (my_strcmp(shell->buf_array[0], "exit") == 0) {
        my_putstr("exit\n");
        free(shell);
        exit(0);
    }
    return 1;
}

int check_builtin(shell_t *shell)
{
    if (check_exit(shell) == 1)
        return 1;
    return 0;
}