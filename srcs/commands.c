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

char *search_in_path(char *path_line, char **buffer, char **path_parsed)
{
    char *cmd = NULL;
    int i = 0;
    int success = 0;

    if (my_strncmp(buffer[0], "cd", 2) == 0)
        return NULL;
    while (success == 0 && i <= count_path(path_line)) {
        cmd = hanled_exec_path(path_parsed[i], buffer[0]);
        if (access(cmd, 1) != -1)
            success = 1;
        else 
            success = 0;
        i += 1;
    }
    if (success == 0)
        return NULL;
    else
        return cmd;
}

int exec_cmd(char **buffer, char *cmd, char **env)
{
    int error = 0;
    pid_t pid = fork();

    if (pid != 0) {
        wait(&error);
        get_segfault(error);
    }else {
        if (execve(cmd, buffer, env) == -1) {
            my_putstr("error\n");
        }
        exit(0);
    }
    return 0;
}

int exec_command(char **env, char **buffer, shell_t *shell)
{
    int built = 0;
    char *cmd = NULL;

    built = check_builtin(buffer);
    cmd = search_in_path(shell->path_line, buffer, shell->path_parsed);
    if (built == -1 && cmd == NULL){
        not_found(buffer[0]);
    }
    if (cmd != NULL) {
        exec_cmd(buffer, cmd, env);
    }
    if (built >= 1){
        do_builtin(built, env, buffer);
    }
    return 0;
}