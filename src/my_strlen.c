/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** .
*/

#include "../include/mysh.h"

int my_strlen(char const *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_strdup(char *str)
{
    int size = 0;
    char *src = NULL;

    size = my_strlen(str) + 1;
    src = malloc(sizeof(char) * size);
    if (!src)
        return (NULL);
    src = my_strcpy(src, str);
    src[size - 1] = '\0';
    return (src);
}

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;
    while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
        i = i + 1;
    if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
        return 0;
    else if (s1[i] > s2[i])
        return 1;
    else
        return -1;
}