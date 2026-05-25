##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## script that help me to compile my function
##

SRC =	*.c

NAME =	USNameFormatter

all: $(NAME)

$(NAME):	$(SRC)
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -f *~
	rm -f *.o
	rm -f *#

fclean:
	rm -f $(NAME)
	rm -f coding-style-reports.log
	clear

re: fclean all

style:
	coding-style .
	cat coding-style-reports.log
