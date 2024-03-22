/*
** EPITECH PROJECT, 2022
** mnsh2
** File description:
** mysh
*/

#include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #define she1 (sh->envp = change_envp(envp),  \
    get_envp_path(sh, envp),  \
    my_putstr("$>"))
    #define she2 (line[size - 1] = '\0',   \
    get_envp_path(sh, sh->envp),  \
    line = clear_str(line), \
    argv = my_str_to_word_array(line))
    #define di1 ( write(2, str, my_strlen(str)),    \
    write(2, ": No such file or directory.\n", 29))
    #define di2 (write(2, str, my_strlen(str)),  \
    write(2, ": Not a directory.\n", 19))
    #define di3 (str = pass_store_pwd(sh), \
    previous_dir(sh),   \
    chdir(str), \
    sh->var_i = 0)
    #define di4 (my_putstr("cd: too many arguments\n"), \
    sh->var_i = 1)
    #define di5 (tmp[a] = ' ', \
    tmp[a + 1] = str[i],    \
    a++)
    #define di6 (tmp[a] = str[i],   \
    tmp[a+ 1] = ' ',    \
    a += 2)
    #define di7 ((i != 0 && (str[i] == ';'  \
    || str[i] == '>' || str[i] == '<'   \
    || str[i] == '|')   \
    && str[i - 1] != ' ' && str[i - 1] != '<' && str[i - 1] != '>'  \
    && str[i - 1] != '|') ? di5 : 0)
    #define di8 (close(fd[0]),   \
    dup2(fd[1], STDOUT_FILENO), \
    do_pipe(tmp, sh),   \
    dup2(stdout_real, STDOUT_FILENO))
    #define di9 (tmp[count] = NULL, \
    close(fd[1]),   \
    dup2(fd[0], STDIN_FILENO),  \
    do_pipe(tmp, sh),   \
    close(fd[0]),   \
    dup2(stdin_real, STDIN_FILENO))
    #define di10 (fd = open(file, O_RDONLY),    \
    dup2(fd, STDIN_FILENO), \
    close(fd))
    #define di11 (tmp = strtok(my_strdup(src), ":"),    \
    src = src + my_strlen(tmp), \
    sh->path[w] = tmp,  \
    sh->path[w][my_strlen(tmp)] = '\0', \
    tmp = strtok(NULL, " "))
    #define di12 (tmp[count] = NULL,   \
    count = 0,  \
    (fork() == 0) ? di8 : 0)
    #define di13 (tmp[count] = argv[i], \
    count++)
    #define di14 (tmp[a + 1] = NULL,   \
    script_checking(tmp, sh),   \
    a = 0,  \
    tmp = malloc(sizeof(char *) * 20))
    #define di15 (tmp[a] = argv[i], \
    a++)
    #define di16 (sh->envp[i] = malloc(sizeof(char)*my_strlen(argv[1])  \
    + 1 + my_strlen(argv[2]) + 1),  \
    new = my_strcat(new, argv[2]))

typedef struct myshe_t
{
    int var_i;
    char **envp;
    char **path;
    char *str;
    int a;
}mysh;

char *pass_store_pwd(mysh *sh);
mysh *previous_dir(mysh *sh);
char **change_envp(char **envp);
mysh *do_envp(mysh *sh);
mysh *do_exit(mysh *sh);
mysh *simple_cd(mysh *sh);
char *get_envp(mysh *sh);
mysh *complexe_cd(char **argv, mysh *sh);
mysh *do_cd(char **argv, mysh *sh);
mysh *my_shell(char **argv, char **envp);
bool new_shell_func(char *str, mysh *sh, char **argv);
mysh *free_all(mysh *sh);
int my_strncmp(char *s1, char *s2, int n);
char *my_strdup(char *str);
void my_putchar(char c);
int count_arg(char **argv);
char **my_str_to_word_array(char *str);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *clear_str(char *str);
int my_strncmp(char *s1, char *s2, int n);
int find_path_pos(char **envp, mysh *sh);
mysh *get_envp_path(mysh *sh, char **envp);
void do_pipe(char **argv, mysh *sh);
mysh *checking_pipe(char **argv, mysh *sh);
mysh *file_redirect(char **argv, mysh *sh);
mysh *semi_colone(char **argv, mysh *sh);
char *real_tunel(char **argv);
mysh *redirect_auto(char **argv);
bool check_path(char **path, char *str, mysh *sh);
mysh *script_checking(char **argv, mysh *sh);
void doing_proc(char *path, char **envp, char **argv, int *a);
int arg_setenvp(mysh *sh, char **argv);
mysh *do_setenvp(mysh *sh, char **argv);
int shell_arg_se(char **argv, mysh *sh);
int for_ans(char **argv, mysh *sh);
mysh *redirect(char **argv, mysh *sh, int a);
int just_cmp(mysh *sh, char *str);
mysh *do_unsetenvp(mysh *sh, char *str);
int have_var(mysh *sh, char **argv);
int my_strcmp(char *str_o, char *str_c);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char *src);
int caracter(char *str, int id);