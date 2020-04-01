/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
    char buffer[READ_SIZE];
    int stock = 0;
    int first_line = 0;
    char *str = malloc(sizeof(char) * READ_SIZE);
    int i = read(fd, buffer, READ_SIZE);

    if (fd == -1 || buffer == NULL || str == NULL || i < 0)
        return (NULL);
    while (buffer[stock] != '\0') {
        if (buffer[stock] == '\n' || buffer[stock + 1] == '\0') {
            stock++;
            return (str);
        }
        str[first_line] = buffer[stock];
        stock += 1;
        first_line += 1;
    }
    return NULL;
}