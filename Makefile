NAME = game

CC = g++
CFLAGS = -Wall -Wextra -Werror
LD_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

BIN_DIR = bin
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

BIN = $(addprefix $(BIN_DIR)/, $(NAME))
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ) -o $@ $(LD_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(BIN)

re: fclean all

.PHONY: all clean fclean re
