##
## EPITECH PROJECT, 2025
## stumper
## File description:
## stumper
##

SRC	=	*.c

OBJ	=	*.o

NAME	=	amazed

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g3

$(OBJ):
	gcc -c $(SRC)

clean:
	rm -f *.o

fclean:	clean
	rm -f *~
	rm -f $(NAME)

re:	fclean all
