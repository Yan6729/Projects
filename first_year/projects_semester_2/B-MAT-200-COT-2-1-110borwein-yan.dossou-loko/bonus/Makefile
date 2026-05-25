##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

LIB = -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window

SRPP =	*.cpp

NAME =	borwein

CC =	g++

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRPP) $(LIB)

clean:
	rm *~

fclean:
	rm -f $(NAME)
	clear

re: all clean fclean
