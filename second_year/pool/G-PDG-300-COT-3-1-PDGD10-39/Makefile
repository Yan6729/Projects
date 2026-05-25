##
## EPITECH PROJECT, 2026
## snd_year_pool
## File description:
## Makefile
##

CC	=	clang++

FILE	=	Stack.cpp	\


NAME	=	unit_tests

all	:	$(NAME)

$(NAME):
	$(CC) -Wall -Wextra -std=c++20 -o $(NAME) $(FILE) tests/tests.cpp -lcriterion --coverage

clean	:
	rm -f *.gcda
	rm -f *.gcno

fclean	:	clean
	rm -f $(NAME)

unit_tests	:	fclean all

tests_run	:	unit_tests
	./unit_tests --version
	./unit_tests --verbose
