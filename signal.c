/*
** EPITECH PROJECT, 2020
** navy
** File description:
** signal management
*/

#include "my.h"

void hit_or_not(int hit)
{
    if (hit == 0) {
        my_putstr(" missed\n\n", 1);
        kill(SIGNAL_INFO.pid_enemy, SIGUSR1);
        usleep(300);
    } else {
        my_putstr(" hit\n\n", 1);
        kill(SIGNAL_INFO.pid_enemy, SIGUSR2);
        usleep(300);
    }
}

void signal_handler(int sig, siginfo_t *info, void *ucontext)
{
    (void) ucontext;
    if (sig == SIGUSR2) {
        SIGNAL_INFO.coordonates = 0;
        SIGNAL_INFO.pid_enemy = info->si_pid;
        return;
    }
    SIGNAL_INFO.coordonates = 1;
    return;
}

void send_the_signal(int signal1, int signal2)
{
    struct sigaction sig_t;

    sig_t.sa_sigaction = signal_handler;
    sigemptyset(&sig_t.sa_mask);
    sig_t.sa_flags = SA_SIGINFO;
    for (int i = 0; i < signal1; i++) {
        kill(SIGNAL_INFO.pid_enemy, SIGUSR1);
        usleep(300);
    }
    kill(SIGNAL_INFO.pid_enemy, SIGUSR2);
    usleep(300);
    for (int j = 0; j < signal2; j++) {
        kill(SIGNAL_INFO.pid_enemy, SIGUSR1);
        usleep(300);
    }
    kill(SIGNAL_INFO.pid_enemy, SIGUSR2);
    usleep(300);
    return;
}

int recup_the_int(void)
{
    int quit = 0;
    int coordonates = 0;
    struct sigaction sig_t;

    sig_t.sa_sigaction = signal_handler;
    sigemptyset(&sig_t.sa_mask);
    sig_t.sa_flags = SA_SIGINFO;
    while (quit != 1) {
        sigaction(SIGUSR1, &sig_t, NULL);
        sigaction(SIGUSR2, &sig_t, NULL);
        pause();
        if (SIGNAL_INFO.coordonates == 0)
            quit = 1;
        coordonates += SIGNAL_INFO.coordonates;
    }
    return (coordonates);
}

int *recup_the_signal(int *buffer)
{
    buffer[0] = recup_the_int();
    buffer[1] = recup_the_int();
    return (buffer);
}
