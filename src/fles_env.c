/*
** EPITECH PROJECT, 2022
** mnsh2
** File description:
** fles_envp
*/

#include "../include/mysh.h"

mysh *do_envp(mysh *sh)
{
    int i = 0;

    while (sh->envp[i]) {
        my_putstr(sh->envp[i]);
        my_putchar('\n');
        i++;
    }
    sh->var_i = 0;
}

mysh *do_exit(mysh *sh)
{
    int exit_number = sh->var_i;

    free_all(sh);
    exit(exit_number);
}