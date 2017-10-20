#ifndef MAIN_H
#define MAIN_H

#define SUDOKU_SIZE 9
#define SUDOKU_ZONE 3
#define EMPTY 0
#define _col_row(c, r, s) ((s).grid[c][r])

typedef int Digit;
typedef struct {
  Digit grid[SUDOKU_SIZE][SUDOKU_SIZE]; // [columns][rows]
} Sudoku;

#endif
