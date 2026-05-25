##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## file to compile my *.c
##

SRC	=	array_main.c	\
		member_functions.c	\


OBJ	=	$(SRC:.c=.o)

LIB	=	libarray.a

all : $(LIB)

$(LIB):	$(OBJ)
	ar rcs $(LIB) $(OBJ)

clean:
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(LIB)
	rm -f $(OBJ)
	rm -f coding-style-reports.log

re: fclean all

style:	clean
	coding-style .
	cat coding-style-reports.log

.PHONY: all re clean valgrind fclean style
