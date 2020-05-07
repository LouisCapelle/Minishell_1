/*
** EPITECH PROJECT, 2020
** commands
** File description:
** commands
*/

#include "my.h"

int get_segfault(int segfault)
{
    if (WIFSIGNALED(segfault)) {
        if (WTERMSIG(segfault) != 8)
            my_putstr(strsignal(WTERMSIG(segfault)));
        else {
            my_putstr("Floating exception\n");
        }
        if (WCOREDUMP(segfault)) {
            my_putstr(" (core dumped)\n");
            return 139;
        }
        return 1;
    }
    return 0;
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
    while (success == 0 && i < count_path(path_line)) {
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
        return (get_segfault(error));
    }else {
        if (execve(cmd, buffer, env) == -1) {
            if (errno == ENOEXEC) {
                my_putstr_noback(cmd);
                my_putstr(": Exed format error. Wrong Architecture.\n");
                exit(0);
                return 1;
            } else if (errno == EACCES) {
                my_putstr_noback(cmd);
                my_putstr(": Permission denied.\n");
                exit(0);
                return 1;
            }
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
        free(cmd);
        return 1;
    }
    if (cmd != NULL) {
        return (exec_cmd(buffer, cmd, env));
        free(cmd);
    }
    if (built >= 1){
        return (do_builtin(built, env, buffer, shell));
        free(cmd);
    }
}