/*
** EPITECH PROJECT, 2020
** exec local
** File description:
** exec_local
*/

#include "my.h"

bool check_access_local(char *cmd)
{
    if (access(cmd, F_OK) != -1)
        return true;
    command_not_found(cmd);
    return false;
}

int exec_local(char **cmd, shell_t *shell)
{
    if (my_strncmp(cmd[0], "./", 2) == 0 && check_access_local(cmd[0]))
        return exec_command(cmd[0], cmd, shell->env);
    else if (my_strncmp(cmd[0], "/", 1) == 0 && check_access_local(cmd[0]))
        return exec_command(cmd[0], cmd, shell->env);
    return 0;
}