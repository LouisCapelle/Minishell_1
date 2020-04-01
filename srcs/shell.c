/*
** EPITECH PROJECT, 2020
** shell
** File description:
** shell
*/

#include "my.h"
#include "get_next_line.h"

shell_t *init_shell(shell_t *shell, char **env)
{
    shell->env = env;
    shell->path_line = get_path_line(env);
    shell->path_parsed = path_to_word_array(shell->path_line);
    return shell;
}

int shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    shell = init_shell(shell, env);
    
    while (1) {
        my_putstr("$>");
        shell->buf = get_next_line(0);
        printf("%s\n", shell->buf);
    }
    return 0;
}