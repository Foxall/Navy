/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include<stdlib.h>
#include<stdio.h>
#include"my.h"

void free_array(char **map, int nb);

char *my_calloc(char *str, int size);

void malloc_array(char **map, int nb, int nbl)
{
    for (int i = 0; i < nbl; i++)
        map[i] = my_calloc(map[i], nb);
}

void give_battlefield(char **map, int nbl, int start)
{
    for (int i = 0; i < 8; i++) {
        map[nbl][start] = '.';
        start++;
        if (i < 7) {
            map[nbl][start] = ' ';
            start++;
        }
    }
    map[nbl][start] = '\n';
}

void give_alpha_firstline(char **map)
{
    int j = 0;

    map[0][j++] = ' ';
    map[0][j++] = '|';
    for (int i = 0; i < 8; i++) {
        map[0][j] = 'A' + i;
        j++;
        if (i < 7) {
            map[0][j] = ' ';
            j++;
        }
    }
    map[0][j] = '\n';
}

char **give_map(void)
{
    char **map = malloc(sizeof(char *) * 11);

    malloc_array(map, 19, 10);
    give_alpha_firstline(map);
    for (int i = 0; i < 17; i++) {
        map[1][i] = '-';
        if (i == 0) {
            i++;
            map[1][i] = '+';
        }
    }
    map[1][17] = '\n';
    for (int i = 1; i < 9; i++) {
        map[i + 1][0] = 48 + i;
        map[i + 1][1] = '|';
        give_battlefield(map, i + 1, 2);
    }
    return (map);
}