##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = libhashtable.a

all:	$(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	rm	-f	$(OBJ)
	rm	-rf	*#
	rm	-rf	*~

fclean:	clean
	rm -f	$(NAME)

re:	fclean	all
