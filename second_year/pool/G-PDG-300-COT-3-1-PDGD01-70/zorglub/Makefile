##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## file to compile my *.c
##

SRC	=	*.c

CC = epiclang

BIN	=	z

FLAGS	=	-std=gnu17 -Wall -Wextra

all : $(BIN)

$(BIN):	$(SRC)
	$(CC) -o $(BIN) $(FLAGS) $(SRC) -g3

clean:
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(BIN)
	rm -f coding-style-reports.log

re: fclean all

valgring: re
	valgrind $(BIN)

style:	fclean
	coding-style .
	cat coding-style-reports.log

.PHONY: all re clean valgrind fclean style
