##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## emacs project
##

SRC	= src/*.c	\
	main/main.c

NAME	= hangman

TEST =	src/*.c

OPT = -lm --coverage -lcriterion

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -f *.o
	rm -f *~
	rm -f src/*~
	rm -f *.gcno
	rm -f *.gcda
	rm -f include/*~
	rm -f include/*#
	rm -f src/*#

fclean: clean
	rm -f $(NAME)
	rm -f coding-style-reports.log
	cp Makefile ../; rm -f *; cp ../Makefile .

re:	fclean all

style:
	coding-style .
	cat coding-style-reports.log

unit_tests: fclean all clean
	gcc -o unit_test $(TEST) tests/test.c $(OPT)

tests_run: unit_tests
	./unit_test

auteur:
	echo $(USER) > auteur

.PHONY: all clean fclean re style unit_tests tests_run auteur
