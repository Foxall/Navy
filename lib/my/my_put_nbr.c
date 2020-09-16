/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** task07
*/
#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-', 1);
        nb = nb * -1;
    }
    if (nb >= 0) {
        if (nb >= 10) {
            my_put_nbr(nb/10);
            my_putchar(nb % 10 + 48, 1);
        } else
            my_putchar(nb + 48, 1);
    }
    return (0);
}
