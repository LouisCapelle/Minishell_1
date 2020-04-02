/*
** EPITECH PROJECT, 2020
** commands
** File description:
** commands
*/

#include "my.h"

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