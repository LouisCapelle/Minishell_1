/*
** EPITECH PROJECT, 2020
** cd
** File description:
** my_cd
*/

#include "my.h"

int get_args(char **args)
{
    int i = 0;

    while (args[i])
        i++;
    return i;
}

int go_path(char *path)
{
    errno = 0;

    if (chdir(path) == -1) {
        if (errno == EACCES) {
            my_putstr(path);
            my_putstr(": Permission denied.\n");
            return 1;
        }
        if (errno == ENOENT) {
            my_putstr(path);
            my_putstr(": No such file or directory.\n");
            return 1;
        }
        if (errno == ENOTDIR) {
            my_putstr(path);
            my_putstr(": Not a directory.\n");
            return 1;
        }
    }
    return 0;
}

int do_cd(char **buffer, char **env)
{
    static int value = 0;
    size_t size = 0;
    static char *save = NULL;
    char *buf = NULL;
    static char *save_path = NULL;
    int status = 0;

    save_path = getcwd(buf, size);
    if (get_args(buffer) < 2) status = go_path(get_env_line("HOME=", env)+5);
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