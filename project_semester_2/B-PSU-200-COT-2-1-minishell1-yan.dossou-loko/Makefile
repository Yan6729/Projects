##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC =	src/*.c	\
	lib/my/*.c

NAME =	mysh

all: $(NAME)

$(NAME):	$(SRC)
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -f *~
	rm -f src/*~
	rm -f lib/my/*~
	rm -f include/*~
	rm -f *#
	rm -f *.out
	rm -f include/*.out
	rm -f src/*.out
	rm -f lib/my/*.out
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
