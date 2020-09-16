/*
** EPITECH PROJECT, 2019
** my_atoi
** File description:
** put an arr in int
*/
#include "my.h"

int my_atoi(char *str)
{
    int size = my_strlen(str);
    int result = 0;
    int i = 0;
    int neg = 0;

    if (str[0] == '-') {
        i = 1;
        neg = 1;
    }
    for (i; i < size; i++) {
        if (i != 0)
            result = result*10;
        result += str[i] - 48;
    }
    if (neg != 0)
        result = result * -1;
    return (result);
}
