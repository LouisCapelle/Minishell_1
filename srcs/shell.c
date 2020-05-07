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
    shell->env = env;
    shell->path_line = get_path_line(env);
    shell->path_parsed = path_to_word_array(shell->path_line);
    shell->path_parsed[0] = shell->path_parsed[0]+5;
    shell->already = 0;
    return shell;
}

int init_command(char **env, char *cmd, shell_t *shell)
{
    int status = 0;
    char **buffer;
    char **parsed;

    if (cmd[0] == ';')
        return 0;
    if (check_separator(cmd) == 0){
        buffer = my_str_to_word_array(cmd);
        status = exec_command(env, buffer, shell);
        free_all(buffer);
        free(cmd);
        return status;
    } else {
        parsed = separtor_to_word_array(cmd);
        status = exec_separators(parsed, shell, cmd);
        free_all(parsed);
        free(cmd);
    }
}

int shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    shell = init_shell(shell, env);
    char *cmd = NULL;
    int status = 0;
    int local = 0;

    while (1) {
        cmd = check_command(env);
        local = check_local(cmd, env);
        if (local == -1)
            status = init_command(env, cmd, shell);
        if (local != -1 && !isatty(STDIN_FILENO))
            return local;
        if (local == -1 && !isatty(STDIN_FILENO))
            return status;
    }
    free(shell);
}