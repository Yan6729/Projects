##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC =	*.c

OBJ = $(SRC:.c=.o)

NAME = libcuddle.a

all:	$(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	rm	-f	*.o
	rm	-rf	*#
	rm	-rf	*~
	rm	-rf	*.out

fclean:
	rm -f $(NAME)
	rm -f coding-style-reports.log

re:	fclean all

style:
	coding-style .
	cat coding-style-reports.log

push: clean fclean
	git add . ; git commit -m "$(COM)"; git push
