/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** compare with numb
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;
    int nb;
    for (i = 0; s1[i] != '\0' && i != n; i++);
    for (nb = 0; s2[nb] != '\0' && nb != n; nb++);
    return (i - nb);
}
