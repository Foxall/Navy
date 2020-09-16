/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copy the n char
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    while (i < n){
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
