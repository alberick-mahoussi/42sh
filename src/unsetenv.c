/*
** EPITECH PROJECT, 2022
** mnsh2
** File description:
** unsetenvp
*/

#include "../include/mysh.h"

int just_cmp(mysh *sh, char *str)
{
    int i = 0;
    while (sh->envp[i]) {
        if (my_strncmp(str, sh->envp[i], (my_strlen(str))) == 0)
            return 1;
        i++;
    }
    return 0;
}

int arg_setenvp(mysh *sh, char **argv)
{
    int i =0;

    for (; argv[i]; i++);
    if (argv[1] == NULL) {
        do_envp(sh);
        return 1;
    }
    if (i >= 4) {
        my_putstr("setenv: Too many arguments.\n");
        sh->var_i = 1;
        return 1;
    }
    return 0;
}

mysh *do_unsetenvp(mysh *sh, char *str)
{
    int i = 0;
    int n = 0;
    char *src = strtok(my_strdup(sh->envp[i]), my_strdup("="));

    sh->var_i = 0;
    if (!str) {
        my_putstr("unsetenv: Too few arguments.\n");
        sh->var_i = 1;
        return (sh);
    } if (just_cmp(sh, str) == 0)
        return (sh);
    while (my_strcmp(str, src) != 0 && sh->envp[i]) {
        i++;
        src = strtok(my_strdup(sh->envp[i]), my_strdup("="));
    } for (n = i; sh->envp[n + 1]; n++)
        sh->envp[n] = sh->envp[n + 1];
    sh->envp[n] = NULL;
}

int have_var(mysh *sh, char **argv)
{
    int a = 0;
    int i = 0;
    char *new = my_strcat(argv[1], "=");
    for (; sh->envp[i]; i++) {
        if (my_strncmp(sh->envp[i], argv[1], my_strlen(argv[1])) == 0) {
            a = 1;
            break;
        }
    }
    if (a == 0)
        return 0;
    if (argv[2])
        di16;
    else
        sh->envp[i] = malloc(sizeof(char)*my_strlen(argv[1]) + 1);
    sh->envp[i] = new;
    return 1;
}

mysh *do_setenvp(mysh *sh, char **argv)
{
    int i = 0;

    sh->var_i = 0;
    if (arg_setenvp(sh, argv) == 1)
        return (sh);
    if (have_var(sh, argv) == 1)
        return (sh);
    for (;sh->envp[i] != NULL;i++);
    if (argv[2] == NULL)
        sh->envp[i] = malloc(sizeof(char)*my_strlen(argv[1])+1);
    else
        sh->envp[i] = malloc(sizeof(char)*my_strlen(argv[1]) +
        1 + my_strlen(argv[2]) + 1);
    my_strcpy(sh->envp[i], argv[1]);
    sh->envp[i] = my_strcat(sh->envp[i], "=");
    if (argv[2] != NULL)
        sh->envp[i] = my_strcat(sh->envp[i], argv[2]);
    sh->envp[i+1] = NULL;
}