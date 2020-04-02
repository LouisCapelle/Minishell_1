/*
** EPITECH PROJECT, 2020
** built_in
** File description:
** built_in
*/

#include "my.h"
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int check_exit(shell_t *shell)
{
    if (my_strncmp(shell->buf_array[0], "exit", 5) == 0) {
        my_putstr("exit\n");
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