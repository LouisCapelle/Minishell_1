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

char  *search_in_path(shell_t *shell)
{
    char *cmd = NULL;
    int i = 0;
    int success = 0;

    cmd = hanled_exec_path(shell->path_parsed[i], shell->buf_array[0]);
    while (success == 0 && i <= count_path(shell->path_line)) {
        cmd = hanled_exec_path(shell->path_parsed[i], shell->buf_array[0]);
        if (access(cmd, 1) != -1)
            success = 1;
        i += 1;
    }
    if (success == 0)
        return NULL;
    else 
        return cmd;
}

int exec_cmd(shell_t *shell, char *cmd)
{
    int error = 0;

    shell->pid = fork();
    if (shell->pid != 0) {
        wait(&error);
        get_segfault(error);
    }else {
        if (execve(cmd, shell->buf_array, shell->env) == -1) {
            my_putstr("error\n");
        }
        exit(0);
    }
    return 0;
}

int exec_command(shell_t *shell)
{
    int built = 0;
    char *cmd = NULL;

    if (shell == NULL)
        return 84;
    built = check_builtin(shell);
    cmd = search_in_path(shell);
    if (built == -1 && cmd == NULL){
        not_found(shell->buf_array[0]);
    }
    if (cmd != NULL) {
        exec_cmd(shell, cmd);
    }
    if (built >= 1)
        return do_builtin(built, shell);
    return 0;
}