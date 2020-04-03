/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "my.h"

int get_args(char **args)
{
    int i = 0;

    if (args == NULL)
        return 84;
    while (args[i])
        i++;
    return i;
}

int go_home(shell_t *shell)
{
    char *home_path = get_home_path(shell->env)+5;

    if (chdir(home_path) != 0)
        my_putstr("Can't change directory\n");
    return 0;
}

int cd(shell_t *shell)
{
    if (get_args(shell->buf_array) < 2)
        go_home(shell);
    if (get_args(shell->buf_array) > 2)
        my_putstr("cd: Too many arguments.\n");
    return 0;
}