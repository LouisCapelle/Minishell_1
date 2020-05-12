/*
** EPITECH PROJECT, 2020
** exec error
** File description:
** exec_error
*/

#include "my.h"

int command_not_found(char *cmd)
{
    my_putstr(cmd);
    my_putstr(": Command not found.\n");
    return 1;
}

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

int exec_error(char *cmd)
{
    if (errno == ENOEXEC) {
        my_putstr_noback(cmd);
        my_putstr(": Exec format error. Wrong Architecture.\n");
        return 1;
    } else if (errno == EACCES) {
        my_putstr_noback(cmd);
        my_putstr(": Permission denied.\n");
        return 1;
    }
    return 0;
}