/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare two string
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i;
    int n;
    for (i = 0; s1[i] != '\0'; i++);
    for (n = 0; s2[n] != '\0'; n++);
    return (i - n);
}
