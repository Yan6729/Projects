##
## EPITECH PROJECT, 2026
## snd_year_pool
## File description:
## Makefile
##

CC	=	clang++

SRC	=	parsing.cpp	\
		instruction.cpp	\
		error_case.cpp	\
		FactoryOperand.cpp	\
		Float64Operand.cpp	\
		Float32Operand.cpp	\
		Int8Operand.cpp	\
		Int16Operand.cpp	\
		Int32Operand.cpp \
		Int64Operand.cpp \
		IOperand.cpp

NAME	=	bistroMatic

all	:	$(NAME)

$(NAME):	$(SRC)
	$(CC) -Wall -Wextra -std=c++20 -o $(NAME) $(SRC)

clean	:
	rm -f *~
	rm -f *#

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all
