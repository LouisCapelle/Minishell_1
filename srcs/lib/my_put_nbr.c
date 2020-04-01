/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** display number
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_put_nbr(int nb)
{
    int stock = nb;
    int i = 1;

    if (nb < 0 && nb != -2147483648) {
        my_putchar('-');
        nb = nb * (-1);
        stock = stock * (-1);
    } if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return (0);
    } while (stock >= 10) {
        stock = stock / 10;
        i = i * 10;
    }
    while (i >= 1) {
        my_putchar(nb / i + 48);
        nb = nb % i;
        i = i / 10;
    }
    return (0);
}
