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
    if (my_strncmp(shell->buf_array[0], "exit", 5) == 0)
        return 0;
    return 1;
}

int check_cd(shell_t *shell)
{
    if (my_strncmp(shell->buf_array[0], "cd",
            my_strlen(shell->buf_array[0])) == 0)
        return 0;
    return 1;
}

int check_builtin(shell_t *shell)
{
    if (check_exit(shell) == 0){
        my_putstr("exit\n");
        exit(0);
    }
    if (check_cd(shell) == 0)
        return 1;
    return -1;
}

int do_builtin(int built, shell_t *shell)
{
    if (built < 1)
        return 0;
    if (built == 1)
        cd(shell);
    return 0;
}