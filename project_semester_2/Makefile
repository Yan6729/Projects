##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC  = 	gcc

SRC = src/*.c	\
	lib/my/*.c

NAME =	42sh

all: $(NAME)

$(NAME):	$(SRC)
	$(CC) -o $(NAME) $(SRC) -g3

clean:
	rm -f *~
	rm -f src/*~
	rm -f lib/my/*~
	rm -f include/*~
	rm -f *#
	rm -f *.out
	rm -f include/*.out
	rm -f src/*.out
	rm -f lib/my/*.out
	rm -f src/*#
	rm -f lib/my/*#
	rm -f include/*#
	rm -rf .vscode

fclean:
	rm -f $(NAME)
	rm -f coding-style-reports.log
	cp Makefile ..; rm * .* ; cp ../Makefile .
	clear

re:	fclean all

valgrind:	re
	valgrind ./$(NAME)

style: clean fclean
	coding-style .
	cat coding-style-reports.log

push: clean fclean
	git add . ; git commit -m "n°$(n): $(COM)"; git push
	clear

.PHONY: all valgrind clean fclean re style push
