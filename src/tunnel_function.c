/*
** EPITECH PROJECT, 2022
** mnsh2
** File description:
** check_advanced
*/

#include "../include/mysh.h"

int shell_arg_se(char **argv, mysh *sh)
{
    int i = 0;
    while (argv[i]) {
        if (my_strcmp(argv[i], "|") == 0) {
            checking_pipe(argv, sh);
            return 1;
        }
        if (my_strcmp(argv[i], "<<") == 0) {
            redirect_auto(argv);
            return 1;
        }
        if (my_strcmp(argv[i], "<") == 0) {
            file_redirect(argv, sh);
            return 1;
        }
        i++;
    }
    return 0;
}

int for_ans(char **argv, mysh *sh)
{
    int i = 0;
    while (argv[i]) {
        if (my_strcmp(argv[i], ";") == 0) {
            semi_colone(argv, sh);
            return 1;
        }
        if (my_strcmp(argv[i], ">") == 0) {
            redirect(argv, sh, 1);
            return 1;
        }
        if (my_strcmp(argv[i], ">>") == 0) {
            redirect(argv, sh, 2);
            return 1;
        }
        if (shell_arg_se(argv, sh))
            return 1;
        i++;
    }
    return 0;
}

mysh *redirect(char **argv, mysh *sh, int a)
{
    char **tmp = malloc(sizeof(char *) * 10);
    int file = 0;
    int stdout_real = dup(STDOUT_FILENO);

    if (a == 1)
        file = open(real_tunel(argv), O_WRONLY | O_CREAT, 0666);
    else if (a == 2)
        file = open(real_tunel(argv), O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (file == -1)
        return (sh);
    dup2(file, STDOUT_FILENO);
    close(file);
    for (int i = 0; argv[i]; i++) {
        if (!my_strcmp(argv[i], ">") || !my_strcmp(argv[i], ">>")) {
            tmp[i + 1] = NULL;
            script_checking(tmp, sh);
        } else
            tmp[i] = argv[i];
    }
    dup2(stdout_real, STDOUT_FILENO);
}

int find_path_pos(char **envp, mysh *sh)
{
    int x = 0;

    while (envp[x][0] != 'P' || envp[x][1] != 'A' || envp[x][2] != 'T'
    || envp[x][3] != 'H' || envp[x][4] != '=')
        x++;
    if (my_strlen(envp[x]) <= 5) {
        sh->path = NULL;
        return -1;
    }
    return x;
}

mysh *get_envp_path(mysh *sh, char **envp)
{
    int x = find_path_pos(envp, sh);
    int i = 0;
    char *src, *tmp;
    int w = 0;

    if (x < 0)
        return (sh);
    src = envp[x] + 5;
    for (int n = 0; src[n] != '\0'; n++)
        if (src[n] == ':')
            i++;
    sh->path = malloc(sizeof(char *) * (i + 2));
    for (; w <= i; w++) {
        di11;
    }
    sh->path[w] = NULL;
}