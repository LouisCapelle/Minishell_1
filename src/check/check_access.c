/*
** EPITECH PROJECT, 2020
** check access
** File description:
** check_access
*/

#include "my.h"

int count_path_args(char **path_parsed)
{
    int i = 0;

    while (path_parsed[i])
        i += 1;
    return i;
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

char *get_cmd_path(char *cmd, shell_t *shell)
{
    char *result = NULL;
    int i = 0;
    int success = 0;
    while (success == 0 && i <= count_path_args(shell->path_parsed) - 1) {
        result = hanled_exec_path(shell->path_parsed[i]+5, cmd);
        if (access(result, 1) != -1)
            success = 1;
        else
            success = 0;
        i += 1;
    }
    if (success == 0)
        return NULL;
    else
        return result;
}