##
## EPITECH PROJECT, 2026
## snd_year_pool
## File description:
## Makefile
##

SRC = Z.cpp

CC = g++

NAME = Z

FLAGS	=	-std=c++20 -Wall -Wextra -Werror

all : $(NAME)

$(NAME)	:	$(SRC)
	$(CC) -o $(NAME) $(SRC) $(FLAGS) -g3

clean	:
	rm -f *~
	rm -f *#

fclean	:	clean
	rm -f $(NAME)
	rm -f coding-style-reports.log

re	:	fclean all

style	:	fclean
	coding-style .
	cat coding-style-reports.log
