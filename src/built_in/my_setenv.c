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

int tab_len(char **tab)
{
    int i = 0;

    while (tab[i])
        i += 1;
    return i;
}

char **create_env_variable(char **buffer, shell_t *shell)
{
    char **new_env = malloc(sizeof(char *) * tab_len(shell->env) + 2);
    char *env_variable = NULL;
    int i = 0;

    while (shell->env[i]) {
        new_env[i] = my_strdup(shell->env[i]);
        i += 1;
    }
    env_variable = my_strdup(buffer[1]);
    env_variable = my_strcat(env_variable, "=");
    env_variable = my_strcat(env_variable, buffer[2]);
    new_env[i] = my_strdup(env_variable);
    new_env[i + 1] = NULL;
    return new_env;
}

int my_setenv(char **buffer, shell_t *shell)
{
    int args = get_args(buffer);

    if (args > 1) {
        shell->env = create_env_variable(buffer, shell);
    } else {
        return prompt_env(shell->env);
    }
    return 0;
}