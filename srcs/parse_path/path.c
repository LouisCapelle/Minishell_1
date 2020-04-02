/*
** EPITECH PROJECT, 2020
** path
** File description:
** path
*/

#include "my.h"

int find_home_line(char **env)
{
    int i = 0;

    while (env) {
        if (my_strncmp(env[i], "HOME=", 5) == 0)
            return i;
        i += 1;
    }
    return -1;
}

char *get_home_path(char **env)
{
    int i = 0;
    int pos_home = find_home_line(env);
    char *result = malloc(sizeof(char) * my_strlen(env[pos_home]));

    while (env[pos_home][i]) {
        result[i] = env[pos_home][i];
        i += 1;
    }
    result[i + 1] = '\0';
    return result;
}

int find_path_line(char **env)
{
    int i = 0;

    while (env) {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            return i;
        i += 1;
    }
    return -1;
}

char *get_path_line(char **env)
{
    int i = 0;
    int pos_path = find_path_line(env);
    char *result = malloc(sizeof(char) * my_strlen(env[pos_path]));

    while (env[pos_path][i]) {
        result[i] = env[pos_path][i];
        i += 1;
    }
    result[i + 1] = '\0';
    return result;
}