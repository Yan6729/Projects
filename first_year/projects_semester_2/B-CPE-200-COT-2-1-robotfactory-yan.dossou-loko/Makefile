##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC =	src/*.c	\
	lib/my/*.c	\
	B-CPE-200_op/*.c

NAME =	asm

all: $(NAME)

$(NAME):	$(SRC)
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -f B-CPE-200_op/*~
	rm -f B-CPE-200_op/*#
	rm -f B-CPE-200_op/*.out
	rm -f *~
	rm -f B-CPE-200_champions/*#
	rm -f B-CPE-200_champions/*~
	rm -f B-CPE-200_champions/*.out
	rm -f src/*~
	rm -f *.out
	rm -f src/*.out
	rm -f lib/my/*~
	rm -f lib/my/*.out
	rm -f include/*~
	rm -f include/*.out
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
