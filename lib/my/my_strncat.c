/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** task03
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int a = 0;
    int b = 0;

    while (dest[a] != '\0') {
        a++;
    }
    while (src[b] != '\0' && b < nb) {
        dest[a] = src[b];
        a++;
        b++;
    }
    return (dest);
}
