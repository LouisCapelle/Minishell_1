/*
** EPITECH PROJECT, 2020
** built_in
** File description:
** built_in
*/

#include "my.h"
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int check_exit(char **buffer)
{
    if (my_strncmp(buffer[0], "exit", 5) == 0)
        return 0;
    return 1;
}

int check_cd(char **buffer)
{
    if (my_strncmp(buffer[0], "cd",
            my_strlen(buffer[0])) == 0)
        return 0;
    return 1;
}

int check_builtin(char **buffer)
{
    if (check_exit(buffer) == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    if (check_cd(buffer) == 0)
        return 1;
    return -1;
}

int do_builtin(int built, char **env, char **buffer)
{
    if (built < 1)
        return 0;
    if (built == 1)
        cd(buffer, env);
    return 0;
}