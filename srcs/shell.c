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
    shell->path_parsed[0] = shell->path_parsed[0]+5;
    return shell;
}

int shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    shell = init_shell(shell, env);
    char *temp = NULL;
    char **buffer = NULL;

    while (1) {
        temp = check_command();
        buffer = my_str_to_word_array(temp);
        exec_command(env, buffer, shell);
        free_all(buffer);
    }
    return 0;
}