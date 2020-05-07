/*
** EPITECH PROJECT, 2020
** sep
** File description:
** exec_separator
*/

#include "my.h"

int check_separator(char *cmd)
{
    int i = 0;
    int result = 0;

    while (cmd[i]) {
        if (cmd[i] == ';')
            result += 1;
        i += 1;
    }
    return result;
}

int get_tours(char *cmd)
{
    int i = 0;
    int result = 0;

    while (cmd[i]) {
        if (cmd[i] == ';' && cmd[i + 1] != '\n')
            result += 1;
        i +=1;
    }
    return result + 1;
}

int exec_separators(char **commands, shell_t *shell, char *cmd)
{
    int status = 0;
    char **temp;
    int i = 0;
    int tours = get_tours(cmd);


    while(i < tours) {
        if (commands[i][0] != '\0' || commands[i][0] != '\n') {
            temp = my_str_to_word_array(commands[i]);
            status = exec_command(shell->env, temp, shell);
            free_all(temp);
        }
        i += 1;
    }
    return status;
}