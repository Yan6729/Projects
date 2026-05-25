##
## EPITECH PROJECT, 2026
## snd_year_pool
## File description:
## Makefile
##

CC	=	g++

FILE	=	seminar/*.cpp

NAME	=	unit_tests

all	:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(FILE) tests/*.cpp -lcriterion --coverage

clean	:
	rm -f *.gcda
	rm -f *.gcno

fclean	:	clean
	rm -f $(NAME)

unit_tests	:	fclean all

tests_run	:	unit_tests
	./unit_tests --version
	./unit_tests --verbose
