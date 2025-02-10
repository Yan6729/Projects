##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC = *.c

NAME = my_sudo

all :	my_sudo

my_sudo :	$(SRC)
	gcc -o $(NAME) $(SRC) -lcrypt
clean :
	rm -f *~
	rm -f my_sudo

fclean :clean
	rm -rf coding-style-reports.log
	rm -rf my_sudo
	clear

re :	fclean all

style :
	coding-style .
	cat coding-style-reports.log
