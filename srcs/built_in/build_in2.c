/*
** EPITECH PROJECT, 2020
** built
** File description:
** built_in_2
*/

#include "my.h"

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
    if (check_env(buffer) == 0)
        return 4;
    return -1;
}

int do_builtin(int built, char **env, char **buffer, shell_t *shell)
{
    if (built < 1)
        return 0;
    if (built == 1)
        return (cd(buffer, env, shell));
    if (built == 2)
        set_env(buffer, env);
    if (built == 3)
        unset_env(buffer, env);
    if (built == 4)
        print_env(env);
    return 0;
}