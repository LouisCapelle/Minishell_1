/*
** EPITECH PROJECT, 2020
** path
** File description:
** path
*/

#include "my.h"

int find_path_line(char **env)
{
    int i = 0;

    while (env) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            return i;
        }
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