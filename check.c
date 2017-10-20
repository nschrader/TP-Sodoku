#include <stdbool.h>
#include <string.h>

#include "check.h"
#include "main.h"

#define SUDOKU_SUM 45

bool check(Sudoku sudoku) {
  Digit columnSum[SUDOKU_SIZE];
  Digit lineSum[SUDOKU_SIZE];
  memset(columnSum, 0, sizeof(Digit)*SUDOKU_SIZE);
  memset(lineSum, 0, sizeof(Digit)*SUDOKU_SIZE);
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++) {
      columnSum[i] += dref_(sudoku, i, j);
      lineSum[i] += dref_(sudoku, j, i);
    }
  }
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    if (columnSum[i] != SUDOKU_SUM || lineSum[i] != SUDOKU_SUM) {
      return false;
    }
  }
  return true;
}
