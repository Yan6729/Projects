##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## emacs project
##

SRC	= src/*.c

NAME	= text_count

TEST =	src/text_count.c	\

OPT = -lm --coverage -lcriterion

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -rf *.o
	rm -rf *~
	rm -rf src/*~
	rm -rf include/*~
	rm -rf include/*#
	rm -rf src/*#

fclean: clean
	rm -rf $(NAME)
	rm -rf coding-style-reports.log

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
