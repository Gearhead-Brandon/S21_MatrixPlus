CC = gcc
CFLAGS = -std=c++17 -Wall -Werror -Wextra -I.

SRCS := $(wildcard S21Matrix/*.cpp)
OBJS := $(patsubst S21Matrix/%.cpp,OBJ/%.o,$(SRCS))
OBJ_DIR = OBJ

EXCLUDE = --exclude "Tests/*" --exclude "S21Matrix/Checks/*" --exclude "S21Matrix/Constructors/CreateMatrix.cpp" \
--exclude "S21Matrix/Display/*" --exclude "S21Matrix/Fillers/*"

all: s21_matrix_oop.a

s21_matrix_oop.a: $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: S21Matrix/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clang:
	clang-format -n S21Matrix/*.hpp S21Matrix/**/*.cpp Tests/*.cpp

test:
	gcc  --coverage -I. ./Tests/main.cpp S21Matrix/**/*.cpp -o test -lgtest -lstdc++ -lm
	./test
	~/.local/bin/gcovr -r . $(EXCLUDE) --html --html-details -o test.html
	google-chrome test.html

clean:
	rm -rf $(OBJ_DIR) *.a test *.gcda *gcno *css *html