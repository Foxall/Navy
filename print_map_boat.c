/*
** EPITECH PROJECT, 2020
** print_map_boat
** File description:
** print map of boat
*/

#include "my.h"

int change_turn(int my_turn, maps_s *board, int first)
{
    if (my_turn == 0) {
        my_turn = 1;
    } else if (first == 1) {
        my_turn = 0;
        first = 0;
    } else {
        my_turn = 0;
        update_the_map(board);
    }
    return (my_turn);
}

void signal_hit(int sig, siginfo_t *info, void *ucontext)
{
    (void) ucontext;
    if (sig == SIGUSR2)
        SIGNAL_INFO.coordonates = 1;
    else
        SIGNAL_INFO.coordonates = 0;
    return;
}

int receive_the_hit(void)
{
    struct sigaction sig_t;

    sig_t.sa_sigaction = signal_hit;
    sigemptyset(&sig_t.sa_mask);
    sig_t.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sig_t, NULL);
    sigaction(SIGUSR2, &sig_t, NULL);
    pause();
    if (SIGNAL_INFO.coordonates == 1) {
        my_putstr(" hit\n\n", 1);
        SIGNAL_INFO.coordonates = 0;
        return (1);
    } else {
        my_putstr(" missed\n\n", 1);
        return (0);
    }

}

int transform_the_letter_to_int(char c)
{
    int i = 'A';
    int j = 1;

    for (; i != c; i++)
        j++;
    return (j);
}

void print_map_boat(char **map)
{
    for (int i = 0; i < 10; i++)
        my_putstr(map[i], 1);
}