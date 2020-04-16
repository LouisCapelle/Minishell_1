/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "my.h"
#include <sys/stat.h>

int get_args(char **args)
{
    int i = 0;

    while (args[i])
        i++;
    return i;
}

int go_home(char **env)
{
    char *home_path = get_home_path(env)+5;

    if (chdir(home_path) != 0)
        perror("home");
    return 0;
}

int go_path(char *path, char **env)
{
    struct stat error;

    write_old_path(env);
    if (chdir(path) != 0) {
        my_putstr(path);
        if (stat(path, &error) == -1) {
            my_putstr(": No such file or directory.\n");
            return 1;
        }
        if (access(path, X_OK) == -1 && access(path, F_OK) == 0)
            my_putstr(": Permission denied.\n");
        if (!S_ISDIR(error.st_mode)) {
            my_putstr(": Not a directory.\n");
        }
    } else {
        write_old_path(env);
        write_new_path(env);
    }
    return 0;
}

int cd(char **buffer, char **env)
{
    int args = 0;

    args = get_args(buffer);
    if (args < 2)
        go_home(env);
    if (args == 2 && buffer[1][0] != '-')
        go_path(buffer[1], env);
    if (args == 2 && buffer[1][0] == '-')
        go_old(env);
    if (args > 2)
        my_putstr("cd: Too many arguments.\n");
    return 0;
}