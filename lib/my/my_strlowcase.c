/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** put all in lowercase
*/

char *my_strlowcase(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] > '@' && str[i] < '[')
            str[i] = str[i] + 32;
    }
    return (str);
}
