/*
** EPITECH PROJECT, 2020
** boat_is_burn
** File description:
** return value of boat is burn
*/

#include "my.h"

int boat_is_touched(int *pos, char **map)
{
    int accross = pos[0];
    int line = pos[1];

    if (map[line + 1][(accross * 2)] != '.') {
        map[line + 1][(accross * 2)] = 'x';
        return (1);
    }
    if (map[line + 1][(accross * 2)] == '.') {
        map[line + 1][(accross * 2)] = 'o';
        return (0);
    }
    return (0);
}

void map_adv_player_boat(char *emp, int value, char **map)
{
    if (value == 1)
        map[emp[1] - 48 + 1][(emp[0] - 65) * 2 + 2] = 'x';
    if (value == 0)
        map[emp[1] - 48 + 1][(emp[0] - 65) * 2 + 2] = 'o';
}