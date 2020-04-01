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
    shell->path_line = get_path_line(env);
    shell->path_parsed = path_to_word_array(shell->path_line);
    printf("%s\n", shell->path_parsed[11]);
    return shell;
}

int shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    shell = init_shell(shell, env);
    return 0;
}