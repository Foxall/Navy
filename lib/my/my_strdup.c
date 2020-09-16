/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** dup a str with malloc
*/
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest;
    int i;
    for (i = 0; src[i] != '\0'; i++);
    dest = malloc(sizeof(char) * (i + 1));
    for (int n = 0; n < i; n++)
        dest[n] = src[n];
    dest[i] = '\0';
    return (dest);
}
