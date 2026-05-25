##
## EPITECH PROJECT, 2026
## snd_year_pool
## File description:
## Makefile
##

SRC	=	DoOp.hs	\

CC = ghc

BIN	=	doop

all	:	$(BIN)

$(BIN)	:
	$(CC) -o $(BIN) $(SRC)

clean	:
	rm -f *.o
	rm -f *.hi

fclean	:	clean
	rm -f $(BIN)

re	:	fclean all

style	:
	lambdananas .

.PHONY	:	all clean fclean re
