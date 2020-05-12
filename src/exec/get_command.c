/*
** EPITECH PROJECT, 2020
** get command
** File description:
** get_command
*/

#include "my.h"

int get_command(shell_t *shell)
{
    char *cmd = NULL;
    size_t len = 2048;
    int eof = 0;
    static int status = 0;

    if (isatty(STDIN_FILENO))
        my_putstr("$>");
    eof = getline(&cmd, &len, stdin);
    if (cmd && cmd[0] != '\0' && cmd[0] != '\n' && check_spaces(cmd) == 0) {
        status = init_command(shell, cmd);
        return status;
    }
    if (eof == -1 && !isatty(0))
        exit(status);
    else if (eof == -1 && isatty(0))
        my_exit(status);
    else
        get_command(shell);
    return 0;
}