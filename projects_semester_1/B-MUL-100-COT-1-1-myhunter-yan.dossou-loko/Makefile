##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## help us to compile all c files
##

SRC = 	my_hunter.c	\
	my_putchar.c	\
	my_putstr.c	\
	game_loop.c	\
	game_animate.c	\
	destroy.c	\
	main.c	\

NAME =	my_hunter

all:	$(NAME)

$(NAME):	$(SRC)
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-system	\
	-lcsfml-window -lcsfml-audio -lcsfml-network

clean:
	rm -f *~
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all
