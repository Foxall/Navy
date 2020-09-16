/*
** EPITECH PROJECT, 2020
** place_boat
** File description:
** return int of if
*/

int return_of_accross(int accrossmin, int accrossmax)
{
    int accross = 1;
    if (accrossmin > accrossmax)
        accross *= -1;
    if (accrossmin == accrossmax)
        accross = 0;
    return (accross);
}

int return_of_line(int linemin, int linemax)
{
    int line = 1;
    if (linemin > linemax)
        line *= -1;
    if (linemin == linemax)
        line = 0;
    return (line);
}

int has_boat_on_map(char **map)
{
    for (int i = 2; i < 10; i++) {
        for (int j = 2; j < 16; j += 2) {
            if (map[i][j] != '.' && map[i][j] != 'x' && map[i][j] != 'o')
                return (0);
        }
    }
    return (1);
}