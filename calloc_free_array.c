/*
** EPITECH PROJECT, 2020
** calloc_free_array
** File description:
** calloc and free file
*/

#include<unistd.h>
#include<stdlib.h>
#include"my.h"

void free_array(char **map, int nb)
{
    for (int i = 0; i < nb; i++)
        free(map[i]);
    free(map);
}

char *my_calloc(char *str, int size)
{
    str = malloc(sizeof(char) * size);
    for (int i = 0; i < size; i++){
        str[i] = '\0';
    }
    return (str);
}