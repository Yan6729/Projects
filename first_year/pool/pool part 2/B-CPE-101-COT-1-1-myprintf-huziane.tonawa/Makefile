##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC = 	my_convert_maj.c\
	my_convert_min.c\
	my_flag_e.c	\
	my_flag_E.c	\
	my_putchar.c	\
	my_putstr.c	\
	my_put_nbr.c	\
	my_putfloat.c	\
	my_putfloat2.c	\
	my_convert_min2.c\
	formatage1.c	\
	formatage2.c	\
	my_printf.c

OBJ = 	$(SRC:.c=.o)

LIB = 	libmy.a

all: $(LIB)

$(LIB) : $(OBJ)
	ar rcs $(LIB) $(OBJ)

clean:
	rm -f *.o

fclean:
	rm -f $(LIB)

re: fclean all
