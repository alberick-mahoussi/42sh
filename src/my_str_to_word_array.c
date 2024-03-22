/*
** EPITECH PROJECT, 2022
** mnsh2
** File description:
** my_str_to_word_array
*/

#include "../include/mysh.h"

int count_word(char *str)
{
    int x = 0;
    int i = 0;
    while (str[i + 1] != '\0') {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            x++;
        }
        i++;
        while (str[i + 1] == ' ') {
            i++;
        }
    }
    x++;
    return x;
}

bool check_alp(char c)
{
    if ((c >= '!' && c <= '9') ||
        (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
        || (c == ';' || c == '>' || c == '<' || c == '|'
        || c == '_' || c == '/' || c == '.'))
        return (true);
    else
        return (false);
}

char **my_str_to_word_array(char *str)
{
    char **new = malloc(sizeof(char *) * (count_word(str) + 1));
    int i = 0;
    int k = 0;

    for (int a = 0;i != count_word(str);) {
        a = 0;
        while (check_alp(str[k]) == false && str[k] != '\0')
            k += 1;
        new[i] = malloc(sizeof(char) * (caracter(str, k) + 1));
        while (check_alp(str[k]) == true) {
            new[i][a] = str[k];
            a += 1;
            k += 1;
        }
        new[i][a] = '\0';
        i += 1;
    }
    new[i] = NULL;
    return (new);
}

int caracter(char *str, int id)
{
    int i = id;
    int a = 0;
    while ((str[i] >= '!' && str[i] <= '9') || (str[i] >= 'a' &&
    str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ';'
    || str[i] == '>' || str[i] == '<' || str[i] == '|' || str[i] == '_'
    || str[i] == '/' || str[i] == '.')) {
        a++;
        i++;
    }
    return a;
}

char *clear_str(char *str)
{
    char *tmp = malloc(sizeof(char) * my_strlen(str)+50);
    unsigned int a = 0;
    int p = 0;

    for (int i = 0;str[i];i++) {
        while ((str[i] == ' ' || str[i] == '\t') && p == 0) {
            i++;
        }
        p = 1;
        if (str[i] == '\t' && (str[i - 1] == '\t' || str[i - 1] == ' ')) {
            continue;
        }
        else {
            di7;
            if (str[i + 1] != '\0' && (str[i] == ';' || str[i] == '>'
            || str[i] == '<' || str[i] == '|') && str[i + 1] != ' '
            && str[i + 1] != '<'
            && str[i + 1] != '>' && str[i + 1] != '|') {
                di6;
                continue;
            }
            else if (str[i] == '\t')
                tmp[a] = ' ';
            else
                tmp[a] = str[i];
            a++;
        }
    }
    tmp[a] = '\0';
    return tmp;
}