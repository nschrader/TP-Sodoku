CC=gcc
CFLAGS=-g -std=c99
PROG=sudoku
SRC=main.c io.c check.c solve.c
OBJ=${SRC:.c=.o}

.PHONY: all clean

all:	main

main:	$(OBJ)
			$(CC) -o $(PROG) $^ $(CFLAGS)

%.o:	%.c
			$(CC) -c -o $@ $< $(CFLAGS)

clean:
			rm -rf *.o $(PROG)
