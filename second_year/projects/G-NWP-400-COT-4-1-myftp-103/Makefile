##
## EPITECH PROJECT, 2026
## snd_year_projects
## File description:
## Makefile
##

CC	=	clang++

SRC	=	src/main.cpp	\
		src/Session.cpp	\
		src/Server.cpp

BIN	=	myftp

OBJ	=	$(SRC:.cpp=.o)

FLAGS	=	-Wall -Wextra -std=c++20

all:	$(BIN)

$(BIN):	$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(BIN) -g3

clean:
	rm -f src/*~
	rm -f src/*#
	rm -f include/*~
	rm -f include/*#
	rm -f *~
	rm -f *#

fclean:	clean
	rm -f $(OBJ)
	rm -f $(BIN)

re:	fclean all

.PHONY:	all clean fclean re
