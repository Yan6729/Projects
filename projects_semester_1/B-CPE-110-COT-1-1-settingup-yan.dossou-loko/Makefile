##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Made compilation more ease for us
##

SRC =	*.c

BIN =	setting_up

all : $(BIN)

$(BIN) :	$(SRC)
	gcc -o $(BIN) $(SRC)

clean :
	rm -f *~
	rm -f *.o
	rm -f *#

fclean :
	rm -f $(BIN)
	rm -f coding-style-reports.log
	clear

re : fclean all

style:
	coding-style .
	cat coding-style-reports.log
