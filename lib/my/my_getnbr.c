/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Task05
*/

int my_getnbr(char *str)
{
    int neg = 1;
    int res = 0;

    while ((*str < 48 || *str > 57)){
        str++;
    }
    if (*(str - 1)  == '-')
        neg = -1;
    while (*str >= '0' && *str <= '9') {
        res = res * 10 + (*str - 48);
        str++;
    }
    return (res * neg);
}
