/*
** EPITECH PROJECT, 2021
** priorities.c
** File description:
** .
*/

#include <fcntl.h>
#include "../include/mysh.h"

int number_elm(char **argv)
{
    int i = 0;

    for (; argv[i]; i++);
    return i + 1;
}

void do_pipe(char **argv, mysh *sh)
{
    if (new_shell_func(argv[0], sh, argv) == 0)
        script_checking(argv, sh);
}

mysh *checking_pipe(char **argv, mysh *sh)
{
    char **tmp = malloc(sizeof(char *) * number_elm(argv));
    int count = 0, fd[2];
    int stdout_real = dup(STDOUT_FILENO);
    int stdin_real = dup(STDIN_FILENO);

    if (pipe(fd) == -1) {
        perror("probleme pipe");
        return (sh);
    }
    for (int i = 0; argv[i]; i++)
        (!my_strcmp(argv[i], "|")) ? di12 : di13;
    di9;
}

mysh *file_redirect(char **argv, mysh *sh)
{
    char **tmp = malloc(sizeof(char *) * number_elm(argv));
    char *file = real_tunel(argv);
    int stdin_real = dup(STDIN_FILENO);
    int fd = 0;

    di10;
    for (int i = 0; argv[i]; i++) {
        if (!my_strcmp(argv[i], "<")) {
            tmp[i + 1] = NULL;
            do_pipe(tmp, sh);
        } else
            tmp[i] = argv[i];
    }
    dup2(stdin_real, STDIN_FILENO);
}