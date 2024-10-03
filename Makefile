NAME = game

CC = g++
CFLAGS = -Wall -Wextra
LD_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

BIN_DIR = bin
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

BIN = $(addprefix $(BIN_DIR)/, $(NAME))
SRC = $(shell find $(SRC_DIR) -name '*.cpp')
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ) -o $@ $(LD_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*

fclean: clean
	rm -f $(BIN)

re: fclean all

.PHONY: all clean fclean re
