/*
** EPITECH PROJECT, 2020
** shell
** File description:
** shell
*/

#include "my.h"

shell_t *init_shell(shell_t *shell, char **env)
{
    shell->env = env;
    return shell;
}

int shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    shell = init_shell(shell, env);
    return 0;
}