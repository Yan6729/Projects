##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

SRC	=	src/*.c


OBJ	=	$(SRC:.c=.o)


NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

clean:
	rm -f $(OBJ)
	clear

fclean: clean
	rm -f $(OBJ)
	rm -f *~
	rm -f src/*~
	rm -f include/*~
	rm -f $(NAME)
	rm -f coding-style-reports.log

re:	fclean all
