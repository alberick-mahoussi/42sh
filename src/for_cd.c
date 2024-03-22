/*
** EPITECH PROJECT, 2022
** mnsh2
** File description:
** for_cd
*/

#include "../include/mysh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

mysh *simple_cd(mysh *sh)
{
    char *str = get_envp(sh);

    if (!str) {
        str = malloc(sizeof(char) * 2);
        my_strcpy(str, ".");
    }
    previous_dir(sh);
    if (chdir(str) == -1)
        sh->var_i = 1;
    else
        sh->var_i = 0;
    return (sh);
}

char *get_envp(mysh *sh)
{
    char **tmp = sh->envp;
    char *str;
    int x = 0;

    while (tmp[x] && (tmp[x][0] != 'H' || tmp[x][1] != 'O' || tmp[x][2] != 'M'
    || tmp[x][3] != 'E' || tmp[x][4] != '='))
        x++;
    if (!tmp[x])
        return NULL;
    str = tmp[x] + 5;
    return str;
}

mysh *is_directory(mysh *sh, char *str)
{
    struct stat size;
    stat(str, &size);

    if (stat(str, &size) == -1) {
        di1;
        return (sh);
    } else if (!S_ISDIR(size.st_mode)) {
        di2;
        return (sh);
    }
}

mysh *complexe_cd(char **argv, mysh *sh)
{
    char *str;

    is_directory(sh, argv[1]);
    if (my_strcmp(argv[1], "-") == 0) {
        di3;
        return (sh);
    }
    previous_dir(sh);
    if (my_strcmp(argv[1], "~") == 0)
        chdir(get_envp(sh));
    else if (chdir(argv[1]) == -1)
        sh->var_i = 1;
    else
        sh->var_i = 0;
}

mysh *do_cd(char **argv, mysh *sh)
{
    int argc = count_arg(argv);

    if (argc > 2) {
        di4;
        return (sh);
    }
    if (argc == 1)
        simple_cd(sh);
    else if (argc == 2)
        complexe_cd(argv, sh);
}