##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## this is a Makefile
##

SRC	=	$(wildcard *.c)

NAME = sort_words

all:	$(NAME)

$(NAME):	$(SRC)
	gcc $(SRC) -o  $(NAME)

clean:
	rm	-f	$(OBJ)
	rm	-rf	*#
	rm	-rf	*~

fclean:
	rm -f	$(NAME)
	rm      -rf     *gch

re:	fclean	all
