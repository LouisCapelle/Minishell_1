/*
** EPITECH PROJECT, 2020
** parse
** File description:
** parce_separator
*/

#include "my.h"

int count_cmd(char *line)
{
    int i = 0;
    int result = 0;

    if (line == NULL || my_strlen(line) <= 5)
        return 84;
    while (line[i])
    {
        if (line[i] == ';')
            result += 1;
        i += 1;
    }
    return result + 1;
}

char **malloc_cmd(char *str)
{
    char **result = malloc(sizeof(char *) * (count_cmd(str) + 1));
    int	i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0') {
        if (str[i] == ';') {
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

char **separtor_to_word_array(char *cmd)
{
    int i = 0;
    int line = 0;
    int c = 0;
    char **result = malloc_cmd(cmd);

    while (cmd[i] != '\0' && cmd[i] != '\n') {
        if (cmd[i] == ';') {
            result[line][c] = '\0';
            line += 1;
            c = 0;
        } else {
            result[line][c] = cmd[i];
            c += 1;
        }
        i += 1;
    }
    result[line][c] = '\0';
    result[line + 1] = NULL;
    return (result);
    free(result);
}