# Makefile for Matrices

ifeq ($(OSTYPE), cygwin)
	TARGET_EXTENSION = .out
elseifeq ($(OSTYPE), mysys)
	TARGET_EXTENSION = .exe
elseifeq ($(OSTYPE), Windows_NT)
	TARGET_EXTENSION = .exe
else
	TARGET_EXTENSION = .out
endif

UNITY_ROOT = ./test/unity
CC = gcc

CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -O2
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wold-style-definition
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_FIXTURES

TARGET_BASE = all_tests
TARGET = $(TARGET_BASE)$(TARGET_EXTENSION)
SRC_FILES = \
	$(UNITY_ROOT)/src/unity.c \
	$(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
	src/matrix.c \
	src/mul.c \
	test/test_matrix.c \
	test/test_multiply.c \
	test/test_runners/test_matrix_runner.c \
	test/test_runners/test_multiply_runner.c \
	test/test_runners/all_tests.c

INC_DIRS = -Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS = -pthread

OBJS = src/mdriver.o src/matrix.o src/mul.o

mdriver: $(OBJS)
	$(CC) $(CFLAGS) $(SYMBOLS) -o mdriver $(OBJS)

mdriver.o: mdriver.c matrix.h mul.h

matrix.o: matrix.c matrix.h

mul.o: mul.c mul.h

.PHONY : test
test:
	$(CC) $(CFLAGS) $(SYMBOLS) $(INC_DIRS) $(SRC_FILES) -o $(TARGET)
	./$(TARGET) -v

.PHONY : clean
clean:
	rm -rf *~ src/*.o test/*.o mdriver $(TARGET)
