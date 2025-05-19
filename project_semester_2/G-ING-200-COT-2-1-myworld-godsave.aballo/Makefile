##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC =	src/*.c	\
	lib/my/*.c

NAME =	my_word

all: $(NAME)

$(NAME):	$(SRC)
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-system	\
	-lcsfml-window -lcsfml-audio -lcsfml-network -lm

clean:
	rm -f *~
	rm -f src/*~
	rm -f include/*~
	rm -f lib/my/*~
	rm -f *#
	rm -f src/*#
	rm -f lib/my/*#
	rm -f include/*#

fclean:
	rm -f $(NAME)
	rm -f coding-style-reports.log
	clear

re:	fclean all

style:
	coding-style .
	cat coding-style-reports.log
