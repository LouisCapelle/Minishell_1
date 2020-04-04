/*
** EPITECH PROJECT, 2020
** errors
** File description:
** check_errors
*/

#include "my.h"
#include <stdio.h>

void not_found(char *cmd)
{
    my_putstr(cmd);
    my_putstr(": Command not found.\n");
}

int check_args(int ac, char **env)
{
    if (ac != 1)
        return 84;
    if (env == NULL || find_path_line(env) == -1)
        return 84;
    return 0;
}

char *check_command(void)
{
    char *cmd = NULL;
    size_t len = 2048;
    int eof = 0;

    if (isatty(STDIN_FILENO))
        my_putstr("$>");
    eof = getline(&cmd, &len, stdin);
    if (cmd && cmd[0] != '\0' && cmd[0] != '\n' )
        return cmd;
    if (eof == -1 && !isatty(STDIN_FILENO)){
        free(cmd);
        exit(0);
    } else if (eof == -1) {
        my_putstr(" exit\n");
        free(cmd);
        exit(0);
    } else {
        free(cmd);
        check_command();
    }
}