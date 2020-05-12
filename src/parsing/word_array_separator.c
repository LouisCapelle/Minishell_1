/*
** EPITECH PROJECT, 2020
** separator
** File description:
** word_array_separator
*/

#include "my.h"

int count_separator(char *line, char carac)
{
    int i = 0;
    int result = 0;

    if (line == NULL || my_strlen(line) <= 5)
        return 84;
    while (line[i])
    {
        if (line[i] == carac)
            result += 1;
        i += 1;
    }
    return result + 1;
}

char **malloc_separator(char *str, char carac)
{
    char **result = malloc(sizeof(char *) * (count_separator(str, ':') + 1));
    int	i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0') {
        if (str[i] == carac) {
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

char **separator_to_word_array(char *separator, char carac)
{
    int i = 0;
    int line = 0;
    int c = 0;
    char **result = malloc_separator(separator, carac);

    while (separator[i] != '\0' && separator[i] != '\n') {
        if (separator[i] == carac) {
            result[line][c] = '\0';
            line += 1;
            c = 0;
        } else {
            result[line][c] = separator[i];
            c += 1;
        }
        i += 1;
    }
    result[line][c] = '\0';
    result[line + 1] = NULL;
    return (result);
    free(result);
}