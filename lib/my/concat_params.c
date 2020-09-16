/*
** EPITECH PROJECT, 2019
** my_concat_params
** File description:
** many str as one
*/
#include <stdlib.h>

char *make_one_str(int argc, char **argv, char *str)
{
    int j = 0;
    for (int n = 0; n < argc; n++) {
        for (int i = 0; argv[n][i] != '\0'; i++) {
            str[j] = argv[n][i];
            j++;
        }
        str[j] = '\n';
        j++;
    }
    j++;
    str[j] = '\0';
    return (str);
}

char *concat_params(int argc, char **argv)
{
    char *dest;
    int i = 0;
    for (int n = 0; n < argc; n++) {
        for (i; argv[n][i] != '\0'; i++);
    }
    dest = malloc(sizeof(char) * (i + 1));
    dest = make_one_str(argc, argv, dest);
    return (dest);
}
