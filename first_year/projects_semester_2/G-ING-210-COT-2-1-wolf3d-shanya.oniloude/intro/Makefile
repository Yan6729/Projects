##
## EPITECH PROJECT, 2025
## test wolf3d
## File description:
## makefile
##

NAME= wolf3d

CFILES= src/*.c

LIBS= -lcsfml-graphics -lcsfml-system -lcsfml-audio

all: compiling

compiling:
	gcc -o $(NAME) $(CFILES) $(LIBS) -g3

clean:
	rm -f $(NAME)
	rm -f *~
	rm -f *#
	rm -f *.log
	rm -f *.out
	rm -f src/*~
	rm -f src/*#
	rm -f src/*.log
	rm -f src/*.out
	rm -f *gcno
	rm -f *gcda
	rm -f coding-style-reports.log

fclean: clean

re: fclean all

coding_style:
	coding-style .
	cat coding-style-reports.log
