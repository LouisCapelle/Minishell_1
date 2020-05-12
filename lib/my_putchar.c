/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** displays a character
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}