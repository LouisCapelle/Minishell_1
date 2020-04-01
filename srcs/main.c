/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** main
*/


#include "my.h"
#include <get_next_line.h>

int main(int ac, char **av, char **ae)
{
    if (check_args(ac, av, ae) == 84) {
        return 84;
    } else {
        return shell(ae);
    }
}