##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	= 	*.c

OBJ 	= 	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):		$(OBJ)
	gcc -o $(NAME) $(OBJ)
	rm \*.o
	cp my.h ../../include
	cp libmy.a ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
