/*
** EPITECH PROJECT, 2020
** navy
** File description:
** game
*/

#include "my.h"

int receive_an_attack(maps_s *board)
{
    int *signal_receive = malloc(sizeof(int) * 2);
    int hit = 0;
    int letter = 'A';

    signal_receive = recup_the_signal(signal_receive);
    for (int i = 1; i != signal_receive[0]; i++)
        letter++;
    my_putchar(letter, 1);
    my_put_nbr(signal_receive[1]);
    my_putchar(':', 1);
    hit = boat_is_touched(signal_receive, board->my_map);
    usleep(600);
    hit_or_not(hit);
    return (0);
}

int send_an_attack(maps_s *board)
{
    char *get_line;
    int letter = 0;
    int hit = 0;

    get_line = input();
    if (get_line == NULL)
        return (84);
    my_putstr(get_line, 0);
    my_putchar(':', 1);
    letter = transform_the_letter_to_int(get_line[0]);
    send_the_signal(letter, get_line[1] - 48);
    hit = receive_the_hit();
    map_adv_player_boat(get_line, hit, board->enemy_map);
    return (0);
}

int start_game(maps_s *board, int my_turn)
{
    int quit = 0;
    int first = 1;

    update_the_map(board);
    while (quit == 0) {
        if (my_turn == 1) {
            quit = send_an_attack(board);
            quit = do_i_won(quit, board);
        } else {
            my_putstr("waiting for enemy's attack...\n", 1);
            quit = receive_an_attack(board);
            quit = do_i_loose(quit, board);
        }
        my_turn = change_turn(my_turn, board, first);
        first = 0;
    }
    return (quit - 1);
}

int host_game(maps_s *board)
{
    int host = getpid();
    struct sigaction sig_t;
    int victory = 0;

    sig_t.sa_sigaction = signal_handler;
    sigemptyset(&sig_t.sa_mask);
    sig_t.sa_flags = SA_SIGINFO;
    my_putstr("my_pid:  ", 1);
    my_put_nbr(host);
    my_putstr("\nwaiting for enemy connection...\n\n", 1);
    connection_protocol_host(&sig_t);
    my_putstr("enemy connected\n\n", 1);
    board->enemy_map = give_map();
    victory = start_game(board, 1);
    return (victory);
}

int user2_game(char *str, maps_s *board)
{
    int host = getpid();
    struct sigaction sig_t;
    int victory = 0;

    sig_t.sa_sigaction = signal_handler;
    sigemptyset(&sig_t.sa_mask);
    sig_t.sa_flags = SA_SIGINFO;
    my_putstr("my_pid:  ", 1);
    my_put_nbr(host);
    my_putchar('\n', 1);
    connection_protocol_usr2(str, &sig_t);
    my_putstr("successfully connected\n\n", 1);
    board->enemy_map = give_map();
    victory = start_game(board, 0);
    return (victory);
}
