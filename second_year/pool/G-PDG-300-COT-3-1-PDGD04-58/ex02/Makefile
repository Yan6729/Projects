##
## EPITECH PROJECT, 2026
## snd_year_pool
## File description:
## Makefile
##

SRC	=	StupidUnitConverter.cpp

CC	=	g++

NAME	=	StupidUnitConverter

FLAGS	=	-std=c++20 -Wall -Wextra -Werror

all	:	$(NAME)

$(NAME)	:	$(SRC)
	$(CC) -o $(NAME) $(SRC) $(FLAGS) -g3

clean	:
	rm -f *~
	rm -f *#

fclean	:	clean
	rm -f coding-style-reports.log
	rm -f $(NAME)

re	:	fclean all

style	:	fclean
	coding-style .
	cat coding-style-reports.log
