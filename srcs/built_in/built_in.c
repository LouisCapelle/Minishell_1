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

int check_builtin(char **buffer)
{
    if (check_exit(buffer) == 0) {
        my_putstr("exit\n");
        free_all(buffer);
        exit(0);
    }
    if (check_cd(buffer) == 0)
        return 1;
    if (check_setenv(buffer) == 0)
        return 2;
    if (check_unsetenv(buffer) == 0)
        return 3;
    return -1;
}

int do_builtin(int built, char **env, char **buffer)
{
    if (built < 1)
        return 0;
    if (built == 1)
        cd(buffer, env);
    if (built == 2)
        set_env(buffer, env);
    if (built == 3)
        unset_env(buffer, env);
    return 0;
}