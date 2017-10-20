#ifndef MAIN_H
#define MAIN_H

#define SUDOKU_SIZE 9

typedef char Digit;

typedef struct {
  Digit grid[SUDOKU_SIZE][SUDOKU_SIZE];
} Sudoku;

#endif
