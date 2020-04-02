/*
** EPITECH PROJECT, 2020
** commands
** File description:
** commands
*/

#include "my.h"

void get_segfault(int segfault)
{
    if (WCOREDUMP(segfault)){
        my_putstr("(core dumped)");
        my_putstr("\n");
    }
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
    int error;

    shell->pid = fork();
    cmd = hanled_exec_path(shell->path_parsed[i], shell->buf_array[0]);
    while (success == 0 && i <= count_path(shell->path_line)) {
        cmd = hanled_exec_path(shell->path_parsed[i], shell->buf_array[0]);
        if (shell->pid != 0) {
            wait(&error);
            get_segfault(error);
            return 1;
        }else if (execve(cmd, shell->buf_array, shell->env) != -1) {
            success = 1;
            return 0;
            exit(0);
        }
        i += 1;
    }
    free(cmd);
    return 0;
}

int exec_command(shell_t *shell)
{
    if (shell == NULL)
        return 84;
    if (check_builtin(shell) == 1){
        if (search_in_path(shell) != 1) {
            not_found(shell->buf_array[0]);
            exit(0);
            free(shell->buf);
            free(shell->buf_array);
        }
    }
    return 0;
}