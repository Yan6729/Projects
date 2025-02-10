##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC = 	my_putchar.c	\
	my_putstr.c	\
	my_put_nbr.c	\
	my_ls.c		\

OBJ = 	my_ls

all: $(OBJ)

$(OBJ) :	$(SRC)
	gcc -o $(OBJ) $(SRC)

clean:
	rm -f *.o
	rm -f *~

fclean:
	rm -f $(OBJ)

re: fclean all
