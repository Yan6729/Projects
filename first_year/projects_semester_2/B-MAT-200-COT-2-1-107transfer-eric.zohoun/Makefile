##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC =	src/*.c

BIN =	107transfer

all: $(BIN)

$(BIN):	$(SRC)
	gcc -o $(BIN) $(SRC) -lm -g3

clean:
	rm -f *~
	rm -f *#
	rm -f src/*~
	rm -f src/*#
	rm -f include/*#
	rm -f include/*~

fclean:
	rm -f $(BIN)
	rm -f coding-style-reports.log
	clear

re:	fclean all

style:
	coding-style .
	cat coding-style-reports.log
