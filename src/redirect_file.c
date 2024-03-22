/*
** EPITECH PROJECT, 2022
** mnsh2
** File description:
** redirect_file
*/

#include "../include/mysh.h"

mysh *semi_colone(char **argv, mysh *sh)
{
    char **tmp = malloc(sizeof(char *) * 20);
    int a = 0;
    for (int i = 0; argv[i]; i++)
        if (my_strcmp(argv[i], ";") == 0)
            di14;
        else
            di15;
    tmp[a + 1] = NULL;
    script_checking(tmp, sh);
}

char *real_tunel(char **argv)
{
    for (int i = 0; argv[i]; i++) {
        if (!my_strcmp(argv[i], ">"))
            return argv[i + 1];
        if (!my_strcmp(argv[i], ">>"))
            return argv[i + 1];
        if (!my_strcmp(argv[i], "<"))
            return argv[i + 1];
    }
    return my_strdup("file");
}

mysh *redirect_auto(char **argv)
{
    int size = 0;
    char *line = NULL;
    size_t len = 0;

    my_putstr(">");
    while ((size = getline(&line, &len, stdin)) != -1) {
        line[size - 1] = '\0';
        if (my_strcmp(real_tunel(argv), line) == 0)
            break;
        my_putstr(">");
    }
}