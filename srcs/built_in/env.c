/*
** EPITECH PROJECT, 2020
** env
** File description:
** env
*/

#include "my.h"

int print_env(char **env)
{
    int i = 0;

    while (env[i]) {
        my_putstr(env[i]);
        my_putchar('\n');
        i += 1;
    }
}

int set_env(char **buffer, char **env)
{
    if (get_args(buffer) < 2)
        print_env(env);
    return 0;
}

int unset_env(char **buffer, char **env)
{
    if (get_args(buffer) == 1)
        my_putstr("unsetenv: Too few arguments.\n");
    return 0;
}