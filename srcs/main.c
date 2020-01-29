/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** main
*/


#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

void shell(shell_t *shell)
{
    my_putstr("$>");
}

void display_infos(char *name, int args, int pid, int child_pid)
{
    my_putstr("Program name: ");
    my_putstr(name);
    my_putchar('\n');
    my_putstr("Nb args: ");
    my_put_nbr(args);
    my_putchar('\n');
    my_putstr("PID: ");
    my_put_nbr(pid);
    my_putchar('\n');
    my_putstr("Child PID: ");
    my_put_nbr(child_pid);
    my_putchar('\n');
}

int main(int ac, char **av, char **ae)
{
    shell_t my_shell;

    if (ac > 1){
        return (84);
    }else{
        shell(&my_shell);
    }
}