/*
** EPITECH PROJECT, 2020
** Navy_2019
** File description:
** In the Navy!!
*/

#include "my.h"

int connections(int argc, char *argv[])
{
    int victory = 0;
    maps_s board;
    if (argc == 2) {
        board.my_map = map_with_boat(argv[1]);
        if (board.my_map == NULL)
            return (victory = 84);
        victory = host_game(&board);
    } else {
        board.my_map = map_with_boat(argv[2]);
        if (board.my_map == NULL)
            return (victory = 84);
        victory = user2_game(argv[1], &board);
    }
    return (victory);
}

void print_help(void)
{
    my_putstr("USAGE\n", 1);
    my_putstr("     ./navy [first_player_pid] navy_positions\n", 1);
    my_putstr("DESCRIPTION\n", 1);
    my_putstr("     first_player_pid: only for the 2nd player.", 1);
    my_putstr(" pid of the first player.\n", 1);
    my_putstr("     navy_positions: file representing", 1);
    my_putstr(" the positions of the ships.\n", 1);
}

int need_help(char *str)
{
    char *buffer = "-h\0";
    int size = my_strlen(buffer);
    int size2 = my_strlen(str);
    int i = 0;

    if (size == size2) {
        for (; str[i] != '\0'; i++) {
            if (str[i] != buffer[i])
                break;
        }
        if (i == size)
            return (1);
    }
    return (0);
}

int main(int argc, char *argv[])
{
    int launch_game = 0;
    int result = 0;

    if (argc <= 1 || argc >= 4)
        return (84);
    launch_game = need_help(argv[1]);
    if (launch_game == 0)
        result = connections(argc, argv);
    else
        print_help();
    return (result);
}
