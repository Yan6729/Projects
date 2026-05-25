##
## EPITECH PROJECT, 2026
## snd_year_projects
## File description:
## Makefile
##

CC	=	g++

SRC	=	src/IComponent.cpp										\
		src/AComponent.cpp										\
		src/AdvancedComponents/AdvancedComponent.cpp			\
		src/AdvancedComponents/4BitsAdderComponent.cpp			\
		src/AdvancedComponents/4BitsDecoderComponent.cpp		\
		src/AdvancedComponents/8BitsShiftRegisterComponent.cpp	\
		src/AdvancedComponents/8ChannelDataSelectorComponent.cpp\
		src/AdvancedComponents/10BitsJohnsonDecadeComponent.cpp	\
		src/AdvancedComponents/12BitsCounterComponent.cpp		\
		src/AdvancedComponents/DualFlipFlopComponent.cpp		\
		src/AdvancedComponents/RandomAcessMemoryComponent.cpp	\
		src/AdvancedComponents/ReadOnlyMemoryComponent.cpp		\
		src/AdvancedComponents/LoggerComponent.cpp				\
		src/AdvancedComponents/8BitsAdderComponent.cpp			\
		src/ElementaryComponents/ElementaryComponent.cpp		\
		src/ElementaryComponents/AndComponent.cpp				\
		src/ElementaryComponents/OrComponent.cpp				\
		src/ElementaryComponents/NotComponent.cpp				\
		src/ElementaryComponents/XorComponent.cpp				\
		src/ElementaryComponents/XnorComponent.cpp				\
		src/ElementaryComponents/NandComponent.cpp				\
		src/ElementaryComponents/NorComponent.cpp				\
		src/GatesComponents/GatesComponent.cpp					\
		src/GatesComponents/4AndComponent.cpp					\
		src/GatesComponents/4NandComponent.cpp					\
		src/GatesComponents/4OrComponent.cpp					\
		src/GatesComponents/4NorComponent.cpp					\
		src/GatesComponents/4XorComponent.cpp					\
		src/GatesComponents/6NotComponent.cpp					\
		src/SpecialComponents/SpecialComponent.cpp				\
		src/SpecialComponents/ClockComponent.cpp				\
		src/SpecialComponents/TrueComponent.cpp					\
		src/SpecialComponents/FalseComponent.cpp				\
		src/SpecialComponents/InputComponent.cpp				\
		src/SpecialComponents/OutputComponent.cpp				\
		src/ComponentFactory.cpp								\
		src/Circuit.cpp											\

TO_TEST	=	src/SpecialComponents/SpecialComponent.cpp				\
			src/SpecialComponents/ClockComponent.cpp				\
			src/SpecialComponents/TrueComponent.cpp					\
			src/SpecialComponents/FalseComponent.cpp				\
			src/SpecialComponents/InputComponent.cpp				\
			src/SpecialComponents/OutputComponent.cpp				\
			src/ElementaryComponents/ElementaryComponent.cpp		\
			src/ElementaryComponents/AndComponent.cpp				\
			src/ElementaryComponents/OrComponent.cpp				\
			src/ElementaryComponents/NotComponent.cpp				\
			src/ElementaryComponents/XorComponent.cpp				\
			src/IComponent.cpp										\
			src/AComponent.cpp										\

OBJ	=	$(SRC:.cpp=.o)	\
		src/main.o

FOR_BONUS	=	$(SRC:.cpp=.o)	\
				bonus/src/Button.o	\
				bonus/src/Calculator.o	\
				bonus/src/CoreEngine.o

TEST =	unit_tests

BIN	=	nanotekspice

FLAGS	=	-Wall -Wextra -std=c++20

all	:	$(BIN)

$(BIN)	: 	$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(BIN) -g3

SFML_FLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system	

clean	:
	rm -f src/*~
	rm -f src/AdvancedComponents/*~
	rm -f src/SpecialComponents/*~
	rm -f src/ElementaryComponents/*~
	rm -f src/GatesComponents/*~
	rm -f *~
	rm -f include/*~
	rm -f include/AdvancedComponents/*~
	rm -f include/SpecialComponents/*~
	rm -f include/GatesComponentts/*~
	rm -f include/ElementaryComponents/*~
	rm -f src/*#
	rm -f src/AdvancedComponents/*#
	rm -f src/SpecialComponents/*#
	rm -f src/ElementaryComponents/*#
	rm -f src/GatesComponentts/*#
	rm -f *#
	rm -f include/*#
	rm -f include/AdvancedComponents/*#
	rm -f include/SpecialComponents/*#
	rm -f include/GatesComponents/*#
	rm -f include/ElementaryComponents/*#
	rm -f *.gcno
	rm -f *gcda

fclean	:	clean
	rm -f $(BIN)
	rm -f $(OBJ)
	rm -f $(TEST)
	rm -f $(FOR_BONUS)
	rm -f calculator

re	:	fclean all

unit_tests:	fclean
	$(CC) $(FLAGS) -o $(TEST) $(TO_TEST) tests/tests.cpp -lcriterion --coverage

tests_run:	unit_tests
	./unit_tests --version
	./unit_tests --verbose

calculator	:	$(FOR_BONUS)
	$(CC) $(FLAGS) -o calculator $(FOR_BONUS) $(SFML_FLAGS) -g3
