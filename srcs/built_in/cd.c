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

int init_going_to_path(char *path, shell_t *shell, char *temp)
{
    int status = 0;
    char old_path[PATH_MAX];

    getcwd(old_path, sizeof(old_path));
    shell->old_path = my_strdup(old_path);
    status = go_path(path);
    if (status == 1)
        shell->old_path = my_strdup(temp);
    else
        shell->already = 1;
    return status;
}

int cd(char **buffer, char **env, shell_t *shell)
{
    int args = get_args(buffer);
    int status = 0;
    static char *temp;

    temp = my_strdup(shell->old_path);
    if (args < 2) {
        status = go_home(env);
        shell->already = 1;
    }
    if (args == 2 && buffer[1][0] != '-') {
        status = init_going_to_path(buffer[1], shell, temp);
    }
    if (args == 2 && buffer[1][0] == '-') {
        status = go_old_path(shell);
    }
    return status;
}