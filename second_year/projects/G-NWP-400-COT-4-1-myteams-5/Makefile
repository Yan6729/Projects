# 
# EPITECH PROJECT, 2026
# Makefile
# File description:
# build rules
#
RUSTC = rustc
RUSTFLAGS = -O -C debuginfo=0
MYTEAMS_LIB_DIR = libs/myteams
RUSTLINK = -L. -L$(MYTEAMS_LIB_DIR) -l myteams -C link-arg=-Wl,-rpath,\$$ORIGIN/$(MYTEAMS_LIB_DIR)
SERVER_SRC = src/server.rs
SERVER_MODS = src/protocol.rs src/runtime.rs src/state.rs src/types.rs src/log_server.rs
CLI_SRC = src/myteams_cli.rs
CLI_MODS = src/log_client.rs

SERVER_BIN = myteams_server
CLI_BIN = myteams_cli

.PHONY: all clean fclean re

all: $(SERVER_BIN) $(CLI_BIN)

$(SERVER_BIN): $(SERVER_SRC) $(SERVER_MODS)
	$(RUSTC) $(RUSTFLAGS) $(RUSTLINK) -o $@ $(SERVER_SRC)

$(CLI_BIN): $(CLI_SRC) $(CLI_MODS)
	$(RUSTC) $(RUSTFLAGS) $(RUSTLINK) -o $@ $(CLI_SRC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(SERVER_BIN) $(CLI_BIN)

re: fclean all
