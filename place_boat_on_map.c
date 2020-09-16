/*
** EPITECH PROJECT, 2020
** quentin
** File description:
** quentin
*/

#include<stdio.h>
#include"my.h"

void update_the_map(maps_s *board)
{
    my_putstr("my_positions:\n", 1);
    print_map_boat(board->my_map);
    my_putstr("\nenemy's positions:\n", 1);
    print_map_boat(board->enemy_map);
    my_putstr("\n", 1);
}

int replace_dot_by_nb(char number, char **map, int line, int accross)
{
    if (map[line + 1][accross * 2 + 2] != '.')
        return (84);
    map[line + 1][accross * 2 + 2] = number;
    return (0);
}

int place_my_boat(char *boat, char **map)
{
    int linemin = boat[3] - 48;
    int linemax = boat[6] - 48;
    int accrossmin = boat[2] - 65;
    int accrossmax = boat[5] - 65;
    int nb = boat[0] - 48;
    int line = return_of_line(linemin, linemax);
    int accross = return_of_accross(accrossmin, accrossmax);

    for (int i = 0; i < nb; i++) {
        if (replace_dot_by_nb(boat[0], map, linemin, accrossmin) == 84)
            return (84);
        linemin += line;
        accrossmin += accross;
    }
    return (0);
}

int place_boat(char **boat, char **map)
{
    for (int i = 0; i < 4; i++) {
        if (place_my_boat(boat[i], map) == 84)
            return (84);
    }
    return (0);
}

int error_manage(char *boat, int k)
{
    int linemin = boat[3] - '0';
    int linemax = boat[6] - '0';
    int accrossmin = boat[2] - 'A' + 1;
    int accrossmax = boat[5] - 'A' + 1;
    int nb = boat[0] - 48;
    int line = linemax - linemin;
    int accross = accrossmax - accrossmin;
    int line_accross;

    line = ABS(line);
    accross = ABS(accross);
    line_accross = line + accross;
    if (nb != (k + 2))
        return (84);
    if (line_accross != nb - 1)
        return (84);
    return (0);
}
