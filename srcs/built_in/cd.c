/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "my.h"
#include <sys/stat.h>
#include <limits.h>;

int get_args(char **args)
{
    int i = 0;

    while (args[i])
        i++;
    return i;
}

int cd(char **buffer, char **env)
{
    static int value = 0;
    size_t size = 0;
    static char *save = NULL;
    char *buf = NULL;
    static char *save_path = NULL;
    int status = 0;

    save_path = getcwd(buf, size);
    if (get_args(buffer) < 2)
        status = go_path(get_home_path(env));
    if (get_args(buffer) == 2 && buffer[1][0] != '-')
        status = go_path(buffer[1]);
    if (get_args(buffer) == 2 && buffer[1][0] == '-' && value > 0)
        status = go_path(save);
    if (get_args(buffer) == 2 && buffer[1][0] == '-' && value <= 0) {
        my_putstr(": No such file or directory.\n"); status = 1;
    }
    if (status == 0) value += 1;
    free(save);
    save = my_strdup(save_path);
    return status;
}