/*
** EPITECH PROJECT, 2020
** built
** File description:
** built_2
*/

#include "my.h"

int check_exit(char **buffer)
{
    if (my_strncmp(buffer[0], "exit", 5) == 0)
        return 0;
    return 1;
}

int check_cd(char **buffer)
{
    if (my_strncmp(buffer[0], "cd", 3) == 0)
        return 0;
    return 1;
}

int check_env(char **buffer)
{
    if (my_strncmp(buffer[0], "env", 3) == 0)
        return 0;
    return 1;
}

int check_setenv(char **buffer)
{
    if (my_strncmp(buffer[0], "setenv", 7) == 0)
        return 0;
    return 1;
}

int check_unsetenv(char **buffer)
{
    if (my_strncmp(buffer[0], "unsetenv", 9) == 0)
        return 0;
    return 1;
}