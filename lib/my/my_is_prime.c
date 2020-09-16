/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** task06 day05
*/

int my_is_prime(int nb)
{
    int div;
    int mul;

    if (nb == 1 || nb == 0)
        return (0);
    for (div = 0; div < nb; div++) {
        for (mul = 0; mul < nb; mul++) {
            if (div * mul == nb)
                return (0);
            if (nb >= 32767)
                return (0);
        }
    }
    return (1);
}
