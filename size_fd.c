/*
** EPITECH PROJECT, 2020
** size_fd.c
** File description:
** size of file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include"my.h"

char *my_str_fd(char *str)
{
    char *bateaux = malloc(sizeof(char) * 50);
    int fd = open(str, O_RDONLY);
    read(fd, bateaux, 50);
    close(fd);
    return (bateaux);
}

int str_false(char *str)
{
    char c;
    int j = 2;

    for (int i = 0; i < 31; i++) {
        c = str[i];
        if (!(c >= '1' && c <= '8') && !(c >= 'A' && c <= 'H')
        && c != ':' && c != '\n')
            return (84);
        if ((i % 8) == 0) {
            if ((c - 48) != j)
                return (84);
            else
                j++;
        }
    }
    return (0);
}

void my_str_parser(char **boat, char *buff)
{
    int line = 0;
    int chara = 0;
    malloc_array(boat, 9, 5);
    for (int i = 0; i < 31; i++) {
        boat[line][chara] = buff[i];
        if (buff[i] == '\n') {
            line++;
            chara = 0;
        } else
            chara++;
    }
}

char **map_with_boat(char *av)
{
    char *buff = my_str_fd(av);
    char **map = give_map();
    int i = str_false(buff);
    char **boat = malloc(sizeof(char **) * 5);

    if (i != 0) {
        free(buff);
        return (NULL);
    }
    my_str_parser(boat, buff);
    free(buff);
    for (int k = 0; k < 4; k++)
        if (error_manage(boat[k], k) == 84)
            return (NULL);
    if (place_boat(boat, map) == 84)
        return (NULL);
    free_array(boat, 5);
    return (map);
}