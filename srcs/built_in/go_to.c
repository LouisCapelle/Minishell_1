/*
** EPITECH PROJECT, 2020
** goto
** File description:
** go_to
*/

#include "my.h"
#include <limits.h>

int go_home(char **env)
{
    char *home_path = get_home_path(env)+5;

    if (chdir(home_path) != 0) {
        if (errno = ENOENT) {
            my_putstr(home_path);
            my_putstr(": No such file or directory.\n");
            return 1;
        }
        if (errno = ENOTDIR) {
            my_putstr(home_path);
            my_putstr(": Not a directory.\n");
            return 1;
        }
        if (errno == EACCES) {
            my_putstr(": Permission denied.\n");
            return 1;
        }
    }
    return 0;
}

int go_path(char *path)
{
    errno = 0;

    if (chdir(path) != 0) {
        if (errno == EACCES) {
            my_putstr(": Permission denied.\n");
            return 1;
        }
        if (errno = ENOTDIR) {
            my_putstr(path);
            my_putstr(": Not a directory.\n");
            return 1;
        }
        if (errno = ENOENT) {
            my_putstr(path);
            my_putstr(": No such file or directory.\n");
            return 1;
        }
    }
}

int go_old_path(shell_t *shell)
{
    char actual_path[PATH_MAX];
    static char *temp;
    int status = 0;

    if (shell->already != 0) {
        temp = my_strdup(shell->old_path);
        getcwd(actual_path, sizeof(actual_path));
        status = go_path(shell->old_path);
        shell->old_path = my_strdup(temp);
        return status;
    } else {
        my_putstr(": No such file or directory.\n");
        return 1;
    }
}