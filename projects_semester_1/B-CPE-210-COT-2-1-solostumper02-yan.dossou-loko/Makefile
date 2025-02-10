##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = palindrome

all:	$(NAME)

$(NAME):	$(SRC)
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -rf *#
	rm -rf *~

fclean:
	rm -f $(NAME)
	clear

re:	fclean	all
