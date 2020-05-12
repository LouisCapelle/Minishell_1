/*
** EPITECH PROJECT, 2020
** check local
** File description:
** check_local
*/

#include "my.h"

bool check_local(char *cmd)
{
    if (my_strncmp(cmd, "./", 2) == 0)
        return true;
    if (my_strncmp(cmd, "/", 1) == 0)
        return true;
    return false;
}