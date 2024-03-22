/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** .
*/

#include "../include/mysh.h"

int main(int argc, char *argv[], char **envp)
{
    if (!(*envp))
        return 84;
    if (argc != 1)
        exit(84);
    my_shell(argv, envp);
    return 0;
}

mysh *my_shell(char **argv, char **envp)
{
    int size = 0;
    size_t s = 0;
    char *line = NULL;
    mysh *sh = malloc(sizeof(mysh));

    she1;
    while ((size = getline(&line, &s, stdin)) != -1) {
        she2;
        if (for_ans(argv, sh) == 1);
        else if (new_shell_func(line, sh, argv) == false)
            script_checking(argv, sh);
        my_putstr("$>");
    }
    exit(sh->var_i);
}

bool new_shell_func(char *str, mysh *sh, char **argv)
{
    (my_strcmp(str, "exit") == 0) ? do_exit(sh) : 0;
    if (my_strcmp(argv[0], "cd") == 0) {
        do_cd(argv, sh);
        return true;
    }
    if (my_strcmp(str, "env") == 0) {
        do_envp(sh);
        return true;
    }
    if (my_strcmp(argv[0], "setenv") == 0) {
        do_setenvp(sh, argv);
        return true;
    }
    if (my_strcmp(argv[0], "unsetenv") == 0) {
        do_unsetenvp(sh, argv[1]);
        return true;
    }
    return false;
}

mysh *free_all(mysh *sh)
{
    free(sh->path);
    int i = 0;
    while (sh->envp[i]) {
        free(sh->envp[i]);
        i++;
    }
    free(sh->envp);
    free(sh);
}