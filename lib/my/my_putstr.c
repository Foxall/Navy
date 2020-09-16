/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** task02 day04
*/
#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
