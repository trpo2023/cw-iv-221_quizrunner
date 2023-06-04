CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
LDFLAGS = -L/usr/local/lib -lcunit
SRC_DIR = src
TEST_DIR = test
OBJ_DIR = obj
BIN_DIR = bin
SRC = $(wildcard $(SRC_DIR)/*.c)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ += $(TEST_SRC:$(TEST_DIR)/%.c=$(OBJ_DIR)/%.o)
EXECUTABLE = $(BIN_DIR)/quiz

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	@mkdir -p $(@D)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXECUTABLE)

$(OBJ_DIR)/func.o: $(SRC_DIR)/func.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $^

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/mytests.o: $(TEST_DIR)/mytests.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)