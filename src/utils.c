/*
** EPITECH PROJECT, 2022
** mnsh2
** File description:
** my_strcpy
*/

#include "../include/mysh.h"

int my_strcmp(char *str_o, char *str_c)
{
    int i = 0;
    int result = 0;

    while ((str_o[i] == str_c[i]) && (str_o[i] != '\0') && (str_c[i] != '\0')) {
        i++;
    }
    result = str_o[i] - str_c[i];
    return (result);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (;src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strcat(char *dest, char *src)
{
    int	i = my_strlen(dest), i2 = my_strlen(src);
    int	j = 0, x = 0;
    char *new = malloc(sizeof(char)*(i + i2 + 1));

    for (; x < (i + i2); x++) {
        if (x < i)
            new[x] = dest[x];
        else {
            new[x] = src[j];
            j++;
        }
    }
    new[x] = '\0';
    return new;
}