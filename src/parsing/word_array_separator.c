/*
** EPITECH PROJECT, 2020
** separator
** File description:
** word_array_separator
*/

#include "my.h"

int count_path(char *line)
{
    int i = 0;
    int result = 0;

    if (line == NULL || my_strlen(line) <= 5)
        return 84;
    while (line[i])
    {
        if (line[i] == ':')
            result += 1;
        i += 1;
    }
    return result + 1;
}

char **malloc_path(char *str)
{
    char **result = malloc(sizeof(char *) * (count_path(str) + 1));
    int	i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0') {
        if (str[i] == ':') {
            result[k] = malloc(sizeof(char) *(j + 1));
            result[k][j] = '\0';
            k++;
            j = 0;
        } else
            j++;
        i++;
    }
    result[k] = malloc(sizeof(char) *(j + 1));
    result[k][j] = '\0';
    return (result);
}

char **path_to_word_array(char *path_line)
{
    int i = 0;
    int line = 0;
    int c = 0;
    char **result = malloc_path(path_line);

    while (path_line[i] != '\0' && path_line[i] != '\n') {
        if (path_line[i] == ':') {
            result[line][c] = '\0';
            line += 1;
            c = 0;
        } else {
            result[line][c] = path_line[i];
            c += 1;
        }
        i += 1;
    }
    result[line][c] = '\0';
    result[line + 1] = NULL;
    return (result);
}