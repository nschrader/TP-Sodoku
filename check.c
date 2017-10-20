#include <stdbool.h>
#include <string.h>

#include "check.h"
#include "main.h"

#define SUDOKU_SUM 45

bool checkSudoku(Sudoku sudoku) {
  Digit columnSum[SUDOKU_SIZE];
  Digit rowSum[SUDOKU_SIZE];
  memset(columnSum, 0, sizeof(Digit)*SUDOKU_SIZE);
  memset(rowSum, 0, sizeof(Digit)*SUDOKU_SIZE);
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      columnSum[i] += _col_row(i, j, sudoku);
      rowSum[i] += _col_row(j, i, sudoku);
    }
  }
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (columnSum[i] != SUDOKU_SUM || rowSum[i] != SUDOKU_SUM) {
      return false;
    }
  }
  return true;
}
