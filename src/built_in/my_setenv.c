/*
** EPITECH PROJECT, 2020
** setenv
** File description:
** my_setenv
*/

#include "my.h"

int prompt_env(char **env)
{
    int i = 0;

    if (!env)
        return 1;
    while (env[i]) {
        my_putstr(env[i]);
        my_putchar('\n');
        i += 1;
    }
    return 0;
}

int create_env_variable(char **buffer, char **env)
{
    return 0;
}

int my_setenv(char **buffer, shell_t *shell)
{
    int args = get_args(buffer);

    if (args > 1) {
        create_env_variable(buffer, shell->env);
    } else {
        return prompt_env(shell->env);
    }
    return 0;
}