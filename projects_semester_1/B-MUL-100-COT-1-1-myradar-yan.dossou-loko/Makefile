##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## help us to compile all c files
##

SRC = 	*.c

NAME =	my_radar

all:	$(NAME)

$(NAME):	$(SRC)
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-system	\
	-lcsfml-window -lcsfml-audio -lcsfml-network -lm -g3

clean:
	rm -f *~
	rm -f *.o
	rm -f *.rdr

fclean:
	rm -f $(NAME)
	clear

re: fclean all
