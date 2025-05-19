##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## emacs project
##

SRC	= src/*.c

NAME	= fridge

TEST =	src/tab_len.c	\
	src/my_str_to_word_array.c	\

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
