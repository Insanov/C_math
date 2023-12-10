CC=gcc
CFLAGS= -g -std=c11 -Wall -Wextra -Werror
LDFLAGS := -lcheck $(shell pkg-config --cflags --libs check) -fprofile-arcs
GCOVFLAGS := --coverage
SOURCES := my_tests.c
OBJECTS := $(SOURCES:.c=.o)
SRC_TEST = s_tests.c

all: clean test gcov_report

gcov_report: test
	lcov -t "report" -o gcov_report.info -c -d .
	genhtml -o rep gcov_report.info

clean:
	rm -rf *.gc* *.o test rep* gcov_report *.info *.a *.dSYM

format:
	clang-format --style=Google -i  *.c *.h 

s21_math.a:
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar rc s21_math.a $(OBJECTS)
	ranlib s21_math.a
	rm -f *.o

test: s21_math.a 
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(SRC_TEST) $^ $(LDFLAGS) -o test
	./test
