/*
** EPITECH PROJECT, 2022
** mnsh2
** File description:
** cd_bultin
*/

#include "../include/mysh.h"

int count_arg(char **argv)
{
    int i = 0;

    for (;argv[i];i++);
    return i;
}

int no_size(char **envp)
{
    int a = 0;

    while (envp[a])
        a++;
    return a;
}

char **change_envp(char **envp)
{
    char **changed = malloc(sizeof(char *) * no_size(envp) + 10);
    int i = 0;

    while (envp[i]) {
        changed[i] = my_strdup(envp[i]);
        i++;
    }
    changed[i] = NULL;
    return changed;
}

char *pass_store_pwd(mysh *sh)
{
    char **tmp = sh->envp;
    char *str;
    int x = 0;

    while (tmp[x] && (tmp[x][0] != 'O' || tmp[x][1] != 'L' || tmp[x][2] != 'D'
    || tmp[x][3] != 'P' || tmp[x][4] != 'W' || tmp[x][5] != 'D'))
        x++;
    if (!tmp[x])
        return NULL;
    str = tmp[x] + 7;
    return str;
}

mysh *previous_dir(mysh *sh)
{
    char *str = getcwd(NULL, 0);
    int x = 0;

    str = my_strcat(my_strdup("OLDPWD="), str);

    while (sh->envp[x] && (sh->envp[x][0] != 'O'
    || sh->envp[x][1] != 'L'
    || sh->envp[x][2] != 'D'
    || sh->envp[x][3] != 'P' || sh->envp[x][4] != 'W'
    || sh->envp[x][5] != 'D'))
        x++;
    sh->envp[x] = malloc(sizeof(char) * my_strlen(str) + 1);
    my_strcpy(sh->envp[x], str);
}