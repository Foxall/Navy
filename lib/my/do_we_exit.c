/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** exit
*/
#include "my.h"

int do_we_exit(char *str)
{
    char *str2 = "exit\0";

    for (int i = 0; str2[i] != '\0'; i++) {
        if (str[i] != str2[i])
            return (0);
    }
    my_putstr("exit\n");
    return (1);
}
