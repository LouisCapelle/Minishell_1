/*
** EPITECH PROJECT, 2020
** errors
** File description:
** check_errors
*/

#include "my.h"

int check_path_exists(char **env)
{
    return 0;
}

int check_args(int ac, char **av, char **env)
{
    if (ac != 1)
        return 84;
    if (env == NULL || check_path_exists(env) == 84)
        return 84;
    return 0;
}