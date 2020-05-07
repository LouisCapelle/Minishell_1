/*
** EPITECH PROJECT, 2020
** goto
** File description:
** go_to
*/

#include "my.h"
#include <limits.h>

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