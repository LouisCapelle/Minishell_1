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
    
}

int my_setenv(char **buffer, shell_t *shell)
{
    int args = get_args(buffer);

    if (args > 1 && check_creating_env_var(buffer, args) == 0) {
        create_env_variable(buffer, shell);
        return 0;
    } else if (args == 1){
        return prompt_env(shell->env);
    }else {
        return 1;
    }
    return 0;
}