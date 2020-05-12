/*
** EPITECH PROJECT, 2020
** check run
** File description:
** check_run
*/

#include "my.h"

int check_spaces(char *cmd)
{
    int i = 0;
    int len = my_strlen(cmd);
    int result = 0;

    while (i != len) {
        if (cmd[i] == ' ')
            result += 1;
        i += 1;
    }
    if (result != len - 1)
        return 0;
    return 1;
}