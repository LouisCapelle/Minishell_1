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
    shell->path_parsed[0] = shell->path_parsed[0]+5;
    return shell;
}

char *hanled_exec_path(char *path_parsed, char *entry)
{
    char *result = NULL;

    if (path_parsed == NULL || entry == NULL)
        return NULL;
    
    result = my_strcat(path_parsed, "/");
    result = my_strcat(result, entry);
    return result;
}

int search_in_path(shell_t *shell)
{
    char *cmd = NULL;
    int i = 0;
    int success = 0;

    cmd = hanled_exec_path(shell->path_parsed[i], shell->buf_array[0]);
    while (success == 0 && i <= count_path(shell->path_line)) {
        cmd = hanled_exec_path(shell->path_parsed[i], shell->buf_array[0]);
        if (execve(cmd, shell->buf_array, shell->env) != -1)
            success = 1;
        i += 1;
    }
    not_found(shell->buf_array[0]);
    return 0;
}

int exec_command(shell_t *shell)
{
    if (shell == NULL || check_command(shell->buf_array) == 84)
        return 84;
    if (check_builtin(shell) == 1){
        search_in_path(shell);
    }
    return 0;
}

int shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    shell = init_shell(shell, env);
    
    while (1) {
        my_putstr("$>");
        shell->buf_array = my_str_to_word_array(get_next_line(0));
        exec_command(shell);
    }
    return 0;
}