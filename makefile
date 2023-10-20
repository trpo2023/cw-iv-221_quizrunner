#Имя компилятора
CC = gcc

#Опции компиляции
CFLAGS = -Wall -Isrc -Itest

#Каталоги с исходными файлами, объектными файлами и исполняемыми файлами
SRC_DIR = src
APP_DIR = $(SRC_DIR)/app
LIB_DIR = $(SRC_DIR)/lib
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test
TEST_APP_DIR = $(TEST_DIR)/app
TEST_LIB_DIR = $(TEST_DIR)/lib

#Исходные файлы
APP_SRCS = $(wildcard $(APP_DIR)/*.c)
LIB_SRCS = $(wildcard $(LIB_DIR)/*.c)
TEST_APP_SRCS = $(wildcard $(TEST_APP_DIR)/*.c)
TEST_LIB_SRCS = $(wildcard $(TEST_LIB_DIR)/*.c)

# Имя исполняемого файла
TARGET = $(BIN_DIR)/quiz_program
TEST_TARGET = $(BIN_DIR)/test_program

# Создаем каталоги obj и bin, если они не существуют
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Создаем список объектных файлов из исходных файлов
APP_OBJS = $(patsubst $(APP_DIR)/%.c, $(OBJ_DIR)/%.o, $(APP_SRCS))
LIB_OBJS = $(patsubst $(LIB_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIB_SRCS))
TEST_APP_OBJS = $(patsubst $(TEST_APP_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_APP_SRCS))
TEST_LIB_OBJS = $(patsubst $(TEST_LIB_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_LIB_SRCS))

# Цель по умолчанию
all: $(TARGET)

# Компиляция исполняемого файла из объектных файлов
$(TARGET): $(APP_OBJS) $(LIB_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

	# Компиляция объектных файлов из исходных файлов при необходимости
	$(OBJ_DIR)/%.o: $(APP_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

	$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

	# Цель для сборки тестов
	test: $(TEST_TARGET)

	# Компиляция исполняемого файла для тестов
	$(TEST_TARGET): $(TEST_APP_OBJS) $(TEST_LIB_OBJS) $(APP_OBJS) $(LIB_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

	# Компиляция объектных файлов для тестов из исходных файлов при необходимости
	$(OBJ_DIR)/%.o: $(TEST_APP_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

	$(OBJ_DIR)/%.o: $(TEST_LIB_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

	# Очистка объектных файлов и исполняемых файлов
	clean:
	rm -f $(APP_OBJS) $(LIB_OBJS) $(TARGET) $(TEST_APP_OBJS) $(TEST_LIB_OBJS) $(TEST_TARGET)

	# Помечаем цели, которые не являются файлами
	.PHONY: all test clean