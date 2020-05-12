/*
** EPITECH PROJECT, 2020
** parse env
** File description:
** parse_env
*/

#include "my.h"

int find_line(char *line, char **env)
{
    int i = 0;

    while (env) {
        if (my_strncmp(env[i], line, my_strlen(line)) == 0)
            return i;
        i += 1;
    }
    return -1;
}

char *get_env_line(char *line, char **env)
{
    int i = 0;
    int pos_path = find_line(line, env);
    char *result = malloc(sizeof(char) * (my_strlen(env[pos_path]) + 1));

    while (env[pos_path][i]) {
        result[i] = env[pos_path][i];
        i += 1;
    }
    result[i] = '\0';
    return result;
}