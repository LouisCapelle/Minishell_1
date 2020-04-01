/*
** EPITECH PROJECT, 2020
** errors
** File description:
** check_errors
*/

#include "my.h"

int check_args(int ac, char **env)
{
    if (ac != 1)
        return 84;
    if (env == NULL || find_path_line(env) == -1)
        return 84;
    return 0;
}