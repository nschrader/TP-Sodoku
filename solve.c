#include <stdbool.h>

#include "solve.h"
#include "main.h"
#include "check.h"

#define shiftOneByIfNotZero(x) ((x) ? (1<<x) : 0)

static Mask searchRow(Sudoku sudoku, int r) {
  Mask m = 0;
  for (int c = 0; c < SUDOKU_SIZE; c++) {
    Digit val = _col_row(c, r, sudoku);
    m |= shiftOneByIfNotZero(val);
  }
  return m;
}

static Mask searchColumn(Sudoku sudoku, int c) {
  Mask m = 0;
  for (int r = 0; r < SUDOKU_SIZE; r++) {
    Digit val = _col_row(c, r, sudoku);
    m |= shiftOneByIfNotZero(val);
  }
  return m;
}

static Mask searchZone(Sudoku sudoku, int col, int row) {
  Mask m = 0;
  int leftCorner = col / SUDOKU_ZONE;
  int topCorner = row / SUDOKU_ZONE;
  for (int c = leftCorner; c < SUDOKU_ZONE; c++) {
    for (int r = topCorner; r < SUDOKU_ZONE; r++) {
      Digit val = _col_row(c, r, sudoku);
      m |= shiftOneByIfNotZero(val);
    }
  }
  return m;
}

static Digit decodeMask(Mask m) {
  bool found = false;
  Digit d;
  for (Digit i = 0; i < SUDOKU_SIZE; i++) {
    if (m ^ (1<<i)) {
      if (found) {
        return EMPTY;
      } else {
        found = true;
        d = i+1;
      }
    }
  }
  return d;
}

static Digit solveCell(Sudoku* sudoku, int c, int r) {
  Mask cMask = searchColumn(*sudoku, c);
  Mask rMask = searchRow(*sudoku, r);
  Mask zMask = searchZone(*sudoku, c, r);
  Mask m = cMask | rMask | zMask;
  Digit d = decodeMask(m);
  _col_row(c, r, *sudoku) = d;
  return d;
}

bool solveSudoku(Sudoku* sudoku) {
  Sudoku backup = *sudoku;
  while (!checkSudoku(*sudoku)) {
    bool found = false;
    for (int c=0; c<SUDOKU_SIZE; c++) {
      for (int r=0; r<SUDOKU_SIZE; r++) {
        if (_col_row(c, r, *sudoku) == EMPTY) {
          if (solveCell(sudoku, c, r) != EMPTY) {
            found = true;
          }
        }
      }
    }
    if (!found) {
      *sudoku = backup;
      return false;
    }
  }
  return true;
}
