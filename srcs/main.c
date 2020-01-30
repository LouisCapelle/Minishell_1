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
#include <signal.h>

int my_cd(shell_t *shell)
{
    
}

void shell(shell_t *shell)
{
    int fd = 1;

    while (fd > 0) {
        fd = read(0, shell->buffer, 4096);
        shell->args = my_str_to_word_array(shell->buffer, ' ');

    }

}

void exit_c(void)
{
    my_putchar('\n');
    my_putstr("$>");
}

char **my_copy_env(char **env)
{
    int i;
    char **tab;

    i = 0;
    while (env[i])
    {
        if (env[i][0] == 'P' && env[i][1] == 'A' &&
            env[i][2] == 'T' && env[i][3] == 'H')
            tab = my_str_to_array(env[i], ':');
        ++i;
    }
    return (tab);
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
        my_shell.path = my_copy_env(ae);
        my_shell.env = ae;
        signal(SIGINT, exit_c);
        shell(&my_shell);
    }
}