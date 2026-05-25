##
## EPITECH PROJECT, 2026
## snd_year_pool
## File description:
## Makefile
##

SRC	=	src/*.cpp	\
		src/modules/*.cpp\
		src/displays/*.cpp	\

BIN	=	MyGKrellm

CC	=	g++

FLAGS	=	-Wall -Wextra -std=c++20

SFML_FLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

all:	$(BIN)

$(BIN)	:	$(SRC)
	$(CC) $(FLAGS) -o $(BIN) $(SRC) $(SFML_FLAGS) -lncurses -g3

clean	:
	rm -rf *~
	rm -rf *#

fclean	:	clean
	rm -f $(BIN)

re	:	fclean all

.PHONY	:	all clean fclean re
