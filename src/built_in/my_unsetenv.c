/*
** EPITECH PROJECT, 2020
** unsetenv
** File description:
** my_unsetenv
*/

#include "my.h"

int delete_env_var(shell_t *shell, char **buffer)
{

}

int my_unsetenv(shell_t *shell, char **buffer)
{
    int args = get_args(buffer);

    if (args > 1)
        return delete_env_var(shell, buffer);
    else if (args == 1) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 1;
    } else {
        return 1;
    }
    return 0;
}