#ifndef MAIN_H
#define MAIN_H

#define SUDOKU_SIZE 9
#define dref_(x, y, z) (x.grid[y][z])

typedef int Digit;
typedef struct {
  Digit grid[SUDOKU_SIZE][SUDOKU_SIZE];
} Sudoku;

#endif
