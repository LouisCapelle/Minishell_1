/*
** EPITECH PROJECT, 2020
** local
** File description:
** l
*/

#include "my.h"

char *parse_cmd_local(char *cmd)
{
    char *result = malloc(sizeof(char *) * my_strlen(cmd));
    int i = 2;
    int y = 0;

    while (cmd[i] != '\0' && cmd[i] != '\n' && cmd[i] != ' ') {
        result[y] = cmd[i];
        i += 1;
        y += 1;
    }
    result[y] = '\0';
    return result;
}

int exec_local(char *cmd, char **env)
{
    char *parsed_cmd = parse_cmd_local(cmd);
    char **buffer = my_str_to_word_array(cmd);
    int error = 0;
    pid_t pid = fork();

    if (pid != 0) {
        wait(&error);
        return get_segfault(error);
    }else {
        if (execve(parsed_cmd, buffer, env) == -1) {
            if (errno == ENOEXEC) {
                my_putstr_noback(cmd);
                my_putstr(": Exed format error. Wrong Architecture.\n");
                exit(0);
            } else if (errno == EACCES) {
                my_putstr_noback(cmd);
                my_putstr(": Permission denied.\n");
                exit(0);
            }
        }
        exit(0);
    }
}

int check_local(char *cmd, char **env)
{
    int status = 0;
    if (my_strncmp(cmd, "./", 2) == 0) {
        return exec_local(cmd, env);
    }
    return -1;
}