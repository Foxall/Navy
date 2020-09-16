/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** task02
*/

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int b = 0;

    while (dest[a] != '\0')
        a++;
    while (src[b] != '\0') {
        dest[a] = src[b];
        b++;
        a++;
    }
    return (dest);
}
