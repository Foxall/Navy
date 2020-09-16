/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** make the my_strstr
*/
#include <unistd.h>

int compare_the_string(int i, char *str, char const *to_find)
{
    int j = 0;
    for (int n = i; str[n] == to_find[j] && str[n] != '\0'; n++) {
        j++;
        if (to_find[j] == '\0')
            return (i);
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int i;
    int find;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[0]) {
            find = compare_the_string(i, str, to_find);
            if (find > 0)
                return (&(str[i]));
        }
    }
    return (NULL);
}
