/*
** EPITECH PROJECT, 2019
** PSU_my_exec_2019
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include <stdbool.h>

int is_charac(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
        || (c >= 33 && c < 47) || (c >= 58 && c <= 64) || c == '/' || c == '_')
        return (1);
    else
        return (0);
}

int count_words(char const *str)
{
    int i = 0;
    int result = 0;

    while (str[i] != '\0') {
        if (is_charac(str[i]) == 1)
            result += 1;
        while (is_charac(str[i]) == 1 && str[i] != '\0')
            i += 1;
        if (str[i] != '\0')
            i += 1;
    }
    return (result);
}

int len_of_word(char const *str, int k)
{
    int len = 0;

    while (is_charac(str[k]) == 1) {
        k += 1;
        len += 1;
    }
    return (len);
}

char **my_str_to_word_array(char *str)
{
    char **result = malloc(sizeof(char *) * (count_words(str) + 1));
    int i = 0;
    int k = 0;
    int a = 0;

    while (i != count_words(str)) {
        a = 0;
        while (is_charac(str[k]) == 0)
            k += 1;
        result[i] = malloc(sizeof(char) * (len_of_word(str, k) + 1));
        while (is_charac(str[k]) == 1) {
            result[i][a] = str[k];
            a += 1;
            k += 1;
        }
        result[i][a] = '\0';
        i += 1;
    }
    result[i] = NULL;
    return (result);
}