##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC =	*.c

NAME =	my_exec

all: $(NAME)

$(NAME):	$(SRC)
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -f *~
	rm -f *#
	rm -f *.o

fclean:
	rm -f $(NAME)
	rm -f coding-style-reports.log
	clear

re:	fclean all

style:
	coding-style .
	cat coding-style-reports.log
