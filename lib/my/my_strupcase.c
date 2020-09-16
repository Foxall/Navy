/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** put allin uppercase
*/

char *my_strupcase(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++){
        if (str[i] > 96 && str[i] < '{')
            str[i] = str[i] - 32;
    }
    return (str);
}
