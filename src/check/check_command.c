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

bool check_first_carac(char carac)
{
    if ((carac >= 'A' && carac <= 'Z') || (carac >= 'a' && carac <= 'z'))
        return true;
    return false;
}

bool check_alpha(char *str)
{
    int i = 0;

    while (str[i]) {
        if ((str[i] < '0' || str[i] > '9')
            && check_first_carac(str[i] == false))
            return false;
        i++;
    }
    return true;
}

int check_creating_env_var(char **buffer, int args)
{
    if (args > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return 1;
    }
    if (!check_first_carac(buffer[1][0])) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return 1;
    } else if (!check_alpha(buffer[1])) {
        my_putstr("setenv: Variable name must"
        "contain alphanumeric characters.\n");
        return 1;
    } else {
        return 0;
    }
    return 0;
}