##
## EPITECH PROJECT, 2026
## snd_year_projects
## File description:
## Makefile
##

RUSTC	=	rustc

RUST_FILES	=	src/main.rs		\

BIN	=	raytracer

all: $(BIN)

$(BIN):	$(RUST_FILES)
	$(RUSTC) -o $(BIN) $(RUST_FILES)

clean:
	rm -f *~
	rm -f *#

fclean:	clean
	rm -f $(BIN)

re:	fclean all
