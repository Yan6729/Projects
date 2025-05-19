##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME		=	connect4
SRC			=	$(wildcard *.c)
EXCP_MAIN	=	$(filter-out connect4.c, $(SRC))
BIN			=	unit_tests
TEST		=	tests/my_codetest.c

all:
	gcc -o $(NAME) *.c -lm -g3

unit_tests: $(TEST) $(EXCP_MAIN)
			gcc -o $(BIN) $(TEST) $(EXCP_MAIN) -lcriterion --coverage -lgcov

tests_run: unit_tests
		./unit_tests  --verbose

clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *~

fclean: clean
	rm -rf *.a
	rm -rf unit_tests
	rm -rf $(NAME)
	rm -rf coding-style-reports.log
	clear;

re: fclean all

style:
	coding-style .
	cat coding-style-reports.log
