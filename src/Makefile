# Основные переменные
CC=gcc
CCFLAGS=-std=c11 -Wall -Werror -Wextra -Isrc
CHKFLAGS=-lcheck -lpthread -lrt -lsubunit
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBM=-lm

# Пути к папкам с исходными файлами и тестами
SRC_DIR=./
TEST_DIR=tests

# Каталог для объектов
OBJ_DIR=obj
TESTS_OBJ_DIR=$(OBJ_DIR)/tests
GCOV_OBJ_DIR=$(OBJ_DIR)/gcov

# Файлы исходного кода и тестов
SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
TEST_SRC_FILES=$(wildcard $(TEST_DIR)/**/*.c) $(wildcard $(TEST_DIR)/*.c)

# Объектные файлы
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
TEST_OBJ_FILES=$(patsubst $(TEST_DIR)/%.c,$(TESTS_OBJ_DIR)/%.o,$(TEST_SRC_FILES))
GCOV_OBJ_FILES=$(patsubst $(SRC_DIR)/%.c,$(GCOV_OBJ_DIR)/%.o,$(SRC_FILES))

# Название библиотеки
LIBRARY=s21_decimal.a

# Цели сборки
all: $(LIBRARY) gcov_report test

# Создание библиотеки
$(LIBRARY): $(OBJ_FILES)
	ar rcs $@ $^

# Сборка тестового приложения
test: $(OBJ_FILES) $(TEST_OBJ_FILES)
	$(CC) $(CCFLAGS) $(OBJ_FILES) $(TEST_OBJ_FILES) -o $@ $(CHKFLAGS) $(LIBM)
	./test

# Сборка и запуск отчета покрытия
gcov_report: $(GCOV_OBJ_FILES) $(TEST_OBJ_FILES)
	$(CC) $(CCFLAGS) $(GCOVFLAGS) $(GCOV_OBJ_FILES) $(TEST_OBJ_FILES) -o $@ $(CHKFLAGS) $(LIBM)
	./gcov_report
	lcov -t "gcov_report" -o gcov_report.info -c -d .
	genhtml -o report gcov_report.info
	rm -f *.gcno *.gcda gcov_report.info
	open report/index.html

# Компиляция объектных файлов для основной программы
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

# Компиляция объектных файлов для тестов
$(TESTS_OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< -o $@

# Компиляция объектных файлов для gcov
$(GCOV_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(GCOV_OBJ_DIR)
	$(CC) $(CCFLAGS) $(GCOVFLAGS) -c $< -o $@

# Чистка артефактов сборки
clean:
	rm -rf $(OBJ_DIR) $(TESTS_OBJ_DIR) $(GCOV_OBJ_DIR) *.a gcov_report test report/

# Полная пересборка проекта
rebuild: clean all

.PHONY: all clean rebuild gcov_report test
