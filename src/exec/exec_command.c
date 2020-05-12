/*
** EPITECH PROJECT, 2020
** exec
** File description:
** exec_command
*/

#include "my.h"

int exec_command(char *cmd, char **buffer, char **env)
{
    int error = 0;
    int status = 0;
    pid_t pid = fork();

    if (pid != 0) {
        wait(&error);
        return (get_segfault(error));
    } else {
        if (execve(cmd, buffer, env) == -1) {
            status = exec_error(buffer[0]);
            exit(status);
            return status;
        }
        exit(0);
    }
    return status;
}

int prepare_command(shell_t *shell, char **parsed_cmd)
{
    char *cmd = get_cmd_path(parsed_cmd[0], shell);

    if (cmd)
        return exec_command(cmd, parsed_cmd, shell->env);
    else
        return command_not_found(parsed_cmd[0]);
    return 0;
}

int init_command(shell_t *shell, char *cmd)
{
    char **parsed_cmd = my_str_to_word_array(cmd);

    if (check_builtins(parsed_cmd[0]))
        return do_builtin(parsed_cmd, shell);
    else if (check_local(parsed_cmd[0]))
        return exec_local(parsed_cmd, shell);
    else {
        return prepare_command(shell, parsed_cmd);
    }
}