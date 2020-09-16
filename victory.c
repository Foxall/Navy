/*
** EPITECH PROJECT, 2020
** navy
** File description:
** victory check
*/

#include "my.h"

char *input(void)
{
    int good = 1;
    char *get_line;
    size_t size = 0;

    while (good != 0) {
        my_putstr("attack: ", 1);
        if (getline(&get_line, &size, stdin) == -1)
            return (NULL);
        if ((get_line[0] >= 'A' && get_line[0] <= 'H') &&
            (get_line[1] > '0' && get_line[1] <= '8'))
            good = 0;
        else
            my_putstr("wrong position\n", 1);
    }
    return (get_line);
}

int quit_lost(int quit, maps_s *board)
{
    if (SIGNAL_INFO.coordonates == 1) {
        my_putstr("I won\n", 1);
        quit = 2;
        SIGNAL_INFO.coordonates = 0;
    } else {
        quit = has_boat_on_map(board->my_map);
        if (quit == 1) {
            my_putstr("Enemy won\n", 1);
            usleep(600);
            kill(SIGNAL_INFO.pid_enemy, SIGUSR2);
            usleep(300);
        } else {
            usleep(600);
            kill(SIGNAL_INFO.pid_enemy, SIGUSR1);
            usleep(300);
        }
    }
    return (quit);
}

int receive_the_loose(int quit)
{
    struct sigaction sig_t;

    sig_t.sa_sigaction = do_enemy_lose;
    sigemptyset(&sig_t.sa_mask);
    sig_t.sa_flags = SA_SIGINFO;
    kill(SIGNAL_INFO.pid_enemy, SIGUSR1);
    usleep(300);
    sigaction(SIGUSR1, &sig_t, NULL);
    sigaction(SIGUSR2, &sig_t, NULL);
    pause();
    if (SIGNAL_INFO.coordonates == 1) {
        my_putstr("I won\n", 1);
        quit = 2;
        SIGNAL_INFO.coordonates = 0;
    }
    return (quit);
}

int quit_win(int quit)
{
    if (quit == 1) {
        my_putstr("Enemy won\n", 1);
        kill(SIGNAL_INFO.pid_enemy, SIGUSR2);
        usleep(300);
    } else {
        quit = receive_the_loose(quit);
    }
    return (quit);
}