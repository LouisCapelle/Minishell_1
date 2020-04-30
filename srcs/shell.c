/*
** EPITECH PROJECT, 2020
** shell
** File description:
** shell
*/

#include "my.h"
#include <limits.h>

shell_t *init_shell(shell_t *shell, char **env)
{
    char path[PATH_MAX];

    getcwd(path, sizeof(path));
    shell->env = env;
    shell->path_line = get_path_line(env);
    shell->path_parsed = path_to_word_array(shell->path_line);
    shell->path_parsed[0] = shell->path_parsed[0]+5;
    shell->old_path = path;
    shell->already = 0;
    return shell;
}

int shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    shell = init_shell(shell, env);
    char *temp = NULL;
    char **buffer;
    int status = 0;

    while (1) {
        temp = check_command(env);
        buffer = my_str_to_word_array(temp);
        status = exec_command(env, buffer, shell);
        if (!isatty(STDIN_FILENO))
            return status;
        free(temp);
        free_all(buffer);
    }
    free(shell);
}