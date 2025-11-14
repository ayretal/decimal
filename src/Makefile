CC = gcc
# CFLAGS = -Wall -Werror -Wextra -std=c11
GCOV_FLAGS = -Wall -Werror -Wextra -fprofile-arcs -ftest-coverage 
CFLAGS = -Wall -Werror -Wextra 
LDFLAGS = -lcheck -lm -lpthread
# -lcheck  -lcheck_pic -lsubunit -lm -lrt -lpthread
SRC_DIR = functions
TEST_DIR = tests

ifeq ($(shell uname -s),Linux)
	LDFLAGS =-lcheck  -lcheck_pic -lsubunit -lm -lrt -lpthread
# GCOV_FLAGS +=-lsubunit -lm
endif
ifeq ($(shell uname -s),Darwin)
	LDFLAGS =-lcheck 
endif

SRC = $(wildcard $(SRC_DIR)/*/*.c)
OBJ_GCOV = $(SRC:.c=.o)
OBJ = $(SRC:.c=.o)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)

.PHONY: all, test, gcov_report, style, clean, s21_decimal.a

all: s21_decimal.a 

clean:
	rm -f s21_decimal.a $(TEST_OBJ) test *.gc* ./tests/*.gc* *.o *.info
	
s21_decimal.a: libr
	ar rcs s21_decimal.a *.o
	rm -f *.o
	ranlib s21_decimal.a

test:gcov_make $(TEST_OBJ) 
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage  tests/*.o *.o -o test $(LDFLAGS) 
	./test
	rm -f *.o *.gc* 

test_gcov: $(TEST_OBJ) gcov_make
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage  *.o tests/*.o -o test $(LDFLAGS)  
	./test


gcov_report: $(TEST_OBJ) test_gcov
	gcov $(TEST_OBJ:.o=.c)
	lcov -c -d . -o coverage.info
	genhtml coverage.info --output-directory report
	open report/index.html
	rm -f *.o *.gc*

gcov_make:
	$(CC) $(GCOV_FLAGS) -c functions/*/*.c 
# $(CC) $(GCOV_FLAGS) -c tests/*.c

libr:
	$(CC) $(CFLAGS) -c functions/*/*.c 

cppchecker:
	cppcheck --enable=all --suppress=missingIncludeSystem  functions/*/*.c s21_decimal.h s21_addition.h tests/*.c tests/testiks.h 

style:
	clang-format -i --style=Google functions/*/*.c *.h tests/*.c 

valgrind:
	gcc functions/*/*.c tests/*.c -lcheck -lsubunit -lm
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=res_leak.txt ./a.out
	grep -e ERROR res_leak.txt
	rm -rf *.gcda
