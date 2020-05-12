/*
** EPITECH PROJECT, 2020
** unsetenv
** File description:
** my_unsetenv
*/

#include "my.h"
#include <stdlib.h>

int delete_env_var(shell_t *shell, char **buffer)
{
    int i = 1;
    int var = 0;
    int line = 0;

    while(buffer[i] != NULL) {
        var = get_args(shell->env);
        printf("%d\n", var);
        line = find_line(buffer[i], shell->env);
        printf("%d\n", line);
        if (line != -1) {
            free(shell->env[line]);
            shell->env[line] = NULL;
            shell->env[line] = shell->env[var - 1];
            shell->env[var - 1] = NULL;
        }
        i += 1;
    }
    return 0;
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