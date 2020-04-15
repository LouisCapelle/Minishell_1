/*
** EPITECH PROJECT, 2020
** env
** File description:
** env
*/

#include "my.h"

int set_env(char **buffer, char **env)
{
    if (get_args(buffer) < 2)
        exec_cmd(buffer, "/usr/bin/env", env);
    return 0;
}

int unset_env(char **buffer, char **env)
{
    if (get_args(buffer) == 1)
        my_putstr("unsetenv: Too few arguments.\n");
    return 0;
}