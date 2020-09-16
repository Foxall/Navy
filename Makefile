##
## EPITECH PROJECT, 2019
## makefile
## File description:
## RUSH
##

SRC	=	navy.c				\
		calloc_free_array.c	\
		map_navy.c			\
		place_boat_on_map.c	\
		size_fd.c			\
		place_boat_on_map_two.c \
		print_map_boat.c    \
		connection_protocol.c   \
		signal.c            \
		game.c				\
		boat_is_burn.c      \
		victory.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	navy

all:		$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) -W -Wextra -Wall -I include -L lib/my/ -lmy

clean:
	make -C lib/my clean
	rm -f $(NAME)
fclean:
	make -C lib/my fclean
	rm -f $(NAME)

re: fclean all
