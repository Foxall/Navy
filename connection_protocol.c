/*
** EPITECH PROJECT, 2020
** navy
** File description:
** connections protocol
*/

#include "my.h"

void do_enemy_lose(int sig, siginfo_t *info, void *ucontext)
{
    (void) ucontext;
    if (sig == SIGUSR2)
        SIGNAL_INFO.coordonates = 1;
    else
        SIGNAL_INFO.coordonates = 0;
    return;
}

int do_i_loose(int quit, maps_s *board)
{
    struct sigaction sig_t;

    sig_t.sa_sigaction = do_enemy_lose;
    sigemptyset(&sig_t.sa_mask);
    sig_t.sa_flags = SA_SIGINFO;

    if (quit == 84)
        return (84);
    sigaction(SIGUSR1, &sig_t, NULL);
    sigaction(SIGUSR2, &sig_t, NULL);
    pause();
    quit = quit_lost(quit, board);
    return (quit);
}

int do_i_won(int quit, maps_s *board)
{
    if (quit == 84)
        return (84);
    quit = has_boat_on_map(board->my_map);
    usleep(600);
    quit = quit_win(quit);
    return (quit);
}

void connection_protocol_host(struct sigaction *sig_t)
{
    sigaction(SIGUSR2, sig_t, NULL);
    pause();
    kill(SIGNAL_INFO.pid_enemy, SIGUSR2);
    sigaction(SIGUSR1, sig_t, NULL);
    pause();
    kill(SIGNAL_INFO.pid_enemy, SIGUSR2);
    sigaction(SIGUSR2, sig_t, NULL);
    pause();
    return;
}

void connection_protocol_usr2(char *str, struct sigaction *sig_t)
{
    kill(my_atoi(str), SIGUSR2);
    sigaction(SIGUSR2, sig_t, NULL);
    pause();
    kill(my_atoi(str), SIGUSR1);
    sigaction(SIGUSR2, sig_t, NULL);
    pause();
    kill(my_atoi(str), SIGUSR2);
}
