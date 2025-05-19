##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME 	=	crocus
CC	=	gcc
SRC	=	decoup_1.c	\
		decoup_2.c	\
		decoup_3.c	\
		main.c	\

all:
	gcc -o crocus $(SRC) -lm -g3

clean:
	rm -rf *.o
	rm -rf *~
	rm -rf *#
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.c~

fclean: clean
	rm -rf *.a
	rm -rf unit_tests
	rm -rf $(NAME)
	clear

re: fclean all
unit_tests : fclean clean
	gcc $(SRC) tests/*.c -lcriterion -lgcov -coverage -o unit_tests
test_run : unit_tests
	./unit_tests
	gcovr
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
