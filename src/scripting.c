/*
** EPITECH PROJECT, 2022
** mnsh2
** File description:
** execution
*/

#include "../include/mysh.h"

bool check_path(char **path, char *str, mysh *sh)
{
    if (!path) {
        my_putstr(my_strcat(str, ": Command not found.\n"));
        sh->var_i = 1;
        return true;
    }
    return false;
}

mysh *script_checking(char **argv, mysh *sh)
{
    char *tmp = malloc(sizeof(char)*500);
    char *test = malloc(sizeof(char)*500);
    char **new = sh->path;

    if (check_path(new, argv[0], sh) == true)
        return (sh);
    if (access(argv[0], X_OK) == 0) {
        doing_proc(argv[0], sh->envp, argv, &(sh->var_i));
        return (sh);
    } for (int i = 0; new[i]; i++) {
        tmp = my_strcat(my_strdup("/"), my_strdup(argv[0]));
        test = my_strcat(my_strdup(new[i]), tmp);
        if (access(test, X_OK) == 0) {
            doing_proc(test, sh->envp, argv, &(sh->var_i));
            return (sh);
        }
    }
    my_putstr(my_strcat(argv[0], my_strdup(": Command not found.\n")));
    sh->var_i = 1;
}

void doing_proc(char *path, char **envp, char **argv, int *a)
{
    *a = 0;
    pid_t pid = fork();
    int	status;

    if (pid == -1)
        return;
    if (pid == 0)
        execve(path, argv, envp);
    else
        waitpid(pid, &status, 0);
}