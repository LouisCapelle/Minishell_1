/*
** EPITECH PROJECT, 2020
** builtin
** File description:
** check_builtins
*/

#include "my.h"
#include <stdbool.h>

bool check_builtins(char *cmd)
{
    if (my_strncmp(cmd, "cd", 3) == 0)
        return true;
    if (my_strncmp(cmd, "exit", 5) == 0)
        return true;
    if (my_strncmp(cmd, "setenv", 7) == 0)
        return true;
    return false;
}

int do_builtin(char **cmd, shell_t *shell)
{
    if (my_strncmp(cmd[0], "cd", 3) == 0)
        return do_cd(cmd, shell->env);
    if (my_strncmp(cmd[0], "exit", 5) == 0)
        my_exit(0);
    if (my_strncmp(cmd[0], "setenv", 7) == 0)
        return my_setenv(cmd, shell);
    return 0;
}