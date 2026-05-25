##
## EPITECH PROJECT, 2026
## snd_year_projects
## File description:
## Makefile
##

CPP	=	g++

SRC	=	src/camera.cpp		\
		src/point3D.cpp		\
		src/ray.cpp			\
		src/rectangle3D.cpp	\
		src/vector3D.cpp	\
		src/sphere.cpp		\
		src/main.cpp		\

BIN	=	raytracer

FLAGS	=	-Wall -Wextra -std=c++20

all: $(BIN)

$(BIN):	$(SRC)
	$(CPP) $(FLAGS) -o $(BIN) $(SRC) -lm

clean:
	rm -rf *~
	rm -rf src/*~
	rm -rf include/*~
	rm -rf rust/*~
	rm -rf *#
	rm -rf src/*#
	rm -rf include/*#
	rm -rf rust/*#

fclean:	clean
	rm -f $(BIN)

re:	fclean all
