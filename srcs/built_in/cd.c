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

int go_path(char *path)
{
    struct stat error;

    if (chdir(path) != 0) {
        my_putstr(path);
        if (stat(path, &error) == -1)
            my_putstr(": No such file or directory.\n");
    }
    return 0;
}

int cd(char **buffer, char **env)
{
    int args = 0;

    args = get_args(buffer);
    if (args < 2)
        go_home(env);
    if (args == 2)
        go_path(buffer[1]);
    if (args > 2)
        my_putstr("cd: Too many arguments.\n");
    return 0;
}