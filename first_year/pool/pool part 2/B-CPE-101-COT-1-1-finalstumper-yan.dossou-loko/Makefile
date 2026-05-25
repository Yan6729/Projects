##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	= 	*.c

LIB	=	libmy.a

all:	OBJ LIBCR

OBJ:
	gcc -c $(SRC)

LIBCR: $(LIB)

$(LIB):
	ar rcs $(LIB) *.o

clean:
	rm -f *.o

fclean:
	rm -f $(LIB)

re: fclean all
