##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME		=	tail
SRC			=	$(wildcard src/*.c)
EXCP_MAIN	=	$(filter-out src/tail.c, $(SRC))
BIN			=	unit_tests
TEST		=	tests/my_tailtest.c

all:
	gcc -o tail src/*.c -lm -g3

unit_tests: $(TEST) $(EXCP_MAIN)
			gcc -o $(BIN) $(TEST) $(EXCP_MAIN) -lcriterion --coverage -lgcov

tests_run: unit_tests
		./unit_tests  --verbose

clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *~
	rm -rf src/*.
	rm -rf src/*~

fclean: clean
	rm -rf *.a
	rm -rf unit_tests
	rm -rf $(NAME)

re: fclean all

.PHONY: all unit_tests tests_run clean fclean
