/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** minishell
*/

#include "my.h"

int main(int ac, __attribute__((unused))char **av, char **env)
{
    if (ac > 2 || find_line("PATH=", env) == -1)
        return 84;
    return minishell(env);
}