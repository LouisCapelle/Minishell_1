/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av, char **ae)
{
    if (check_args(ac, ae) == 84) {
        return 84;
    } else {
        return shell(ae);
    }
}