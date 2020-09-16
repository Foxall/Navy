/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** lib
*/
#include <unistd.h>

void my_putchar(char c, int n)
{
    write (n, &c, 1);
}
