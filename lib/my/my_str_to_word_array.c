/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** array
*/
#include <stdlib.h>

int str_len2(char const *str)
{
    int i = 0;
    int count = 1;
    for (i; str[i] != '\0'; i++) {
        if (str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\t'))
            count++;
    }
    return (count);
}

char **put_the_str_in_arr(char **arr, char const *str)
{
    int j = 0;
    int count_str = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        j = 0;
        while (str[i] != ' ' && str[i] != '\t' && str[i + 1] != '\0') {
            arr[count_str][j] = str[i];
            i++;
            j++;
        }
        if (j != 0)
            count_str += 1;
    }
    return (arr);
}

char **my_str_to_word_array(char const *str)
{
    int count_str = 0;
    int count_char = 0;
    int nb_str = str_len2(str);
    char **array_return = malloc(sizeof(char *) * nb_str + 1);

    for (int i = 0; str[i] != '\0'; i++) {
        count_char = 0;
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0') {
            count_char += 1;
            i++;
        }
        if (count_char != 0) {
            array_return[count_str] = malloc(sizeof(char) * count_char + 1);
            count_str += 1;
        }
    }
    array_return = put_the_str_in_arr(array_return, str);
    return (array_return);
}
