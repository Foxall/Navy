/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** task04 day05
*/

int my_compute_power_rec(int nb, int p)
{
    int n = 0;
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    if (nb > 32767)
        return (0);
    if (n < p)
        nb = my_compute_power_rec(nb, p - 1) * nb;
    return (nb);
}
