##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC = *.c

NAME = fizzbuzz

all :	$(NAME)

$(NAME) :	$(SRC)
	gcc -o $(NAME) $(SRC) -g3
clean :
	rm -f *~
	rm -f *#

fclean :clean
	rm -rf coding-style-reports.log
	rm -rf $(NAME)
	clear

re :	fclean all

style :
	coding-style .
	cat coding-style-reports.log
