/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** minshell
*/

#include "my.h"

shell_t *init_minishell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));

    shell->path_line = get_env_line("PATH=", env);
    shell->path_parsed = separator_to_word_array(shell->path_line, ':');
    shell->env = env;
    return shell;
}

int minishell(char **env)
{
    shell_t *shell = init_minishell(env);
    int status = 0;

    while (1) {
        status = get_command(shell);
    }
    free(shell);
    return status;
}