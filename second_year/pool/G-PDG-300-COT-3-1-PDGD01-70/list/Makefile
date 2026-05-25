##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## file to compile my *.c
##

SRC	=	list_main.c	\
		complement.c	\
		member_function.c	\

OBJ	=	$(SRC:.c=.o)

LIB	=	liblist.a

all : $(LIB)

$(LIB):	$(OBJ)
	ar rcs $(LIB) $(OBJ)

clean:
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(LIB)
	rm -f coding-style-reports.log

re: flcean all

style:	clean
	coding-style .
	cat coding-style-reports.log

.PHONY: all re clean valgrind fclean style
