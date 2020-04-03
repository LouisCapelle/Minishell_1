/*
** EPITECH PROJECT, 2020
** errors
** File description:
** check_errors
*/

#include "my.h"
#include "get_next_line.h"

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

    my_putstr("$>");
    cmd = get_next_line(0);
    while (cmd == NULL || cmd[0] == '\0' ||
        cmd[0] == ' ' || cmd[0] == '\n') {
        free(cmd);
        my_putstr("$>");
        cmd = get_next_line(0);
    }
    return cmd;
    free(cmd);
}