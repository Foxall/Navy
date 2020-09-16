/*
** EPITECH PROJECT, 2019
** my
** File description:
** task02
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define ABS(value) ((value < 0) ? value * -1 : value)
#define SIGNAL_INFO sig_s

struct signal_info
{
    pid_t my_pid;
    pid_t pid_enemy;
    int coordonates;
} sig_s;

typedef struct maps
{
    char **my_map;
    char **enemy_map;
} maps_s;

void my_putchar(char c, int );

int my_isneg(int nb);

int my_put_nbr(int nb);

void my_swap(int *a, int *b);

int my_putstr(char const *str, int i);

int my_strlen(char const *str);

int my_getnbr(char const *str);

void my_sort_int_array(int *tab, int size);

int my_compute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

char *my_strstr (char *str, char const *to_find);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

char *my_strdup (char const *);

char *concat_params (int , char **);

int my_show_word_array (char * const *);

char **my_str_to_word_array (char const *);

char *make_one_str(int , char **, char *);

int str_len2(char const *);

int my_strcount(char const *);

int compare_the_string(int , char *, char const *);

int my_atoi(char *);

int do_we_exit(char *);

int replace_dot_by_nb(char number, char **map, int line, int accross);

int place_my_boat(char *boat, char **map);

int place_boat(char **boat, char **map);

int error_manage(char *boat, int k);

char *my_str_fd(char *str);

int str_false(char *str);

void my_str_parser(char **boat, char *buff);

char **map_with_boat(char *av);

void free_array(char **map, int nb);

char *my_calloc(char *str, int size);

void malloc_array(char **map, int nb, int nbl);

void give_battlefield(char **map, int nbl, int start);

void give_alpha_firstline(char **map);

char **give_map(void);

int return_of_accross(int accrossmin, int accrossmax);

int return_of_line(int linemin, int linemax);

int has_boat_on_map(char **map);

void print_map_boat(char **);

void connection_protocol_host(struct sigaction *sig_t);

void connection_protocol_usr2(char *str, struct sigaction *sig_t);

void signal_handler(int sig, siginfo_t *info, void *ucontext);

void send_the_signal(int signal1, int signal2);

int *recup_the_signal(int *buffer);

int recup_the_int(void);

void update_the_map(maps_s *board);

int do_i_loose(int quit, maps_s *board);

int do_i_won(int quit, maps_s *board);

int start_game(maps_s *board, int my_turn);

int host_game(maps_s *board);

int user2_game(char *str, maps_s *board);

int transform_the_letter_to_int(char c);

int boat_is_touched(int *, char **);

int receive_the_hit(void);

void map_adv_player_boat(char *emp, int value, char **map);

int change_turn(int my_turn, maps_s *board, int first);

void hit_or_not(int hit);

int quit_win(int quit);

int quit_lost(int quit, maps_s *board);

void do_enemy_lose(int sig, siginfo_t *info, void *ucontext);

char *input(void);