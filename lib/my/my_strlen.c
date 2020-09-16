/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** task03 day04
*/
#include <stddef.h>

int my_strlen(char const *str , int j)
{
    int i = 0;
    if (str == NULL)
        return (i);
    if (j == 1)
        for (; str[i] != '\0'; i++);
    else
        for (; str[i] != '\0' && str[i] != '\n'; i++);
    return (i);
}
