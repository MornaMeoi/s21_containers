CC = g++
CPP_FLAGS = -Werror -Wall -Wextra
# DEBUG_FLAGS = -fsanitize=address -g -O0
DEBUG_FLAGS = -g -O0
CPP_STANDARD = -std=c++17

TARGET = s21_containers
TEST_DIR = tests
TEST_SRCS = $(TEST_DIR)/*.cc

.PHONY: all clean test build rebuild clang cpp_check valgrind

OS := $(shell uname)

ifeq ($(OS), Linux)
	GTEST = $(shell pkg-config --libs --cflags gtest)
	OPEN = xdg-open
else

MAC := $(shell uname -m)

ifeq ($(MAC), arm64)
	GTEST := -I/opt/homebrew/opt/gtest/include -L/opt/homebrew/opt/gtest/lib -lgtest
	OPEN = open
endif
ifeq ($(MAC), x86_64)
	MAC_OS = -mmacosx-version-min=13.6
	GTEST = $(shell pkg-config --libs --cflags gtest)
	OPEN = open
endif

endif

all: rebuild
rebuild: clean build

build: test

test: 
	$(CC) $(CPP_FLAGS) $(CPP_STANDARD) $(DEBUG_FLAGS) $(TEST_SRCS) -o test $(GTEST) $(MAC_OS)
	./test

clean:
	rm -rf test *.o $(TARGET) ../.DS_Store *.dSYM report
	rm -rf *.gcno *.gcda *.gcov *.info s21_containers.a
	# rm -rf ../.vscode 

reset:
	reset

test_vector: clean reset
	$(CC) $(CPP_FLAGS) $(CPP_STANDARD) $(DEBUG_FLAGS) tests/test_vector.cc tests/test_main.cc -o test $(GTEST) $(MAC_OS)
	./test
test_set: clean reset
	$(CC) $(CPP_FLAGS) $(CPP_STANDARD) $(DEBUG_FLAGS) tests/test_set.cc tests/test_main.cc -o test $(GTEST) $(MAC_OS)
	./test
test_list: clean reset
	$(CC) $(CPP_FLAGS) $(CPP_STANDARD) $(DEBUG_FLAGS) tests/test_list.cc tests/test_main.cc -o test $(GTEST) $(MAC_OS)
	./test
test_map: clean reset
	$(CC) $(CPP_FLAGS) $(CPP_STANDARD) $(DEBUG_FLAGS) tests/test_map.cc tests/test_main.cc -o test $(GTEST) $(MAC_OS)
	./test
test_array: clean reset
	$(CC) $(CPP_FLAGS) $(CPP_STANDARD) $(DEBUG_FLAGS) tests/test_array.cc tests/test_main.cc -o test $(GTEST) $(MAC_OS)
	./test
test_multiset: clean reset
	$(CC) $(CPP_FLAGS) $(CPP_STANDARD) $(DEBUG_FLAGS) tests/test_multiset.cc tests/test_main.cc -o test $(GTEST) $(MAC_OS)
	./test
test_stack: clean reset
	$(CC) $(CPP_FLAGS) $(CPP_STANDARD) $(DEBUG_FLAGS) tests/test_stack.cc tests/test_main.cc -o test $(GTEST) $(MAC_OS)
	./test
test_queue: clean reset
	$(CC) $(CPP_FLAGS) $(CPP_STANDARD) $(DEBUG_FLAGS) tests/test_queue.cc tests/test_main.cc -o test $(GTEST) $(MAC_OS)
	./test

add_db_flag:
	$(eval CPP_FLAGS += $(DEBUG_FLAGS))
gcov_flag:
	$(eval CPP_FLAGS += --coverage)
gcov_report: clean gcov_flag add_db_flag test
	mkdir -p report
ifeq ($(OS), Linux)
	lcov --no-external --capture --directory . --output-file coverage.info --rc lcov_branch_coverage=0
else
	lcov --ignore-errors deprecated --ignore-errors inconsistent --no-external --capture --directory . --output-file coverage.info --rc lcov_branch_coverage=0
endif
	genhtml coverage.info -o report --rc lcov_branch_coverage=0
	rm -rf *.gcno *.gcda *.gcov *.info
	open report/index.html
	rm -rf *.o test *.a *.gc* *.info *.out coverage

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i --style=Google $(SRCS) *.h $(TEST_SRCS)
	rm .clang-format

valgrind: rebuild test_compile
	valgrind --tool=memcheck --leak-check=yes -q ./test
	make clean
	
my_test:
	$(CC) $(CPP_FLAGS) $(CPP_STANDARD) test.cpp
