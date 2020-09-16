/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** rev the string
*/

char *my_revstr(char *str)
{
    int letter;
    int n = 0;
    int a = 0;

    while (str[n] != '\0')
        n++;
    n--;
    while ( a < n) {
        letter = str[n];
        str[n] = str[a];
        str[a] = letter;
        a++;
        n--;
    }
    return (str);
}
