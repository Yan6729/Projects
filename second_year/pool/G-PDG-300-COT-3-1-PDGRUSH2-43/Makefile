##
## EPITECH PROJECT, 2026
## makefile
## File description:
## makefile
##

CC = ghc
 
GHCFLAGS = -Wall -Werror
 
BINARY = pushswap_checker
 
SRC	=	pushswap_checker.hs	\
		My.hs	\
		error.hs	\
		function.hs	\


all: $(BINARY)
 
$(BINARY): $(SRC)
	$(CC) -o $(BINARY) $(SRC)
 
re: fclean all
 
clean:
	rm -f *.o *.hi
 
fclean: clean
	rm -f $(BINARY)
 
.PHONY: all re clean fclean
 