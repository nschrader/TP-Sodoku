#include <stdlib.h>
#include <stdio.h>

#include "io.h"
#include "main.h"

Sudoku readSudoku(FILE* file) {
  Sudoku sudoku;
  Digit val;
  for (int r=0; r<SUDOKU_SIZE; r++) {
    for (int c=0; c<SUDOKU_SIZE; c++) {
      if (fscanf(file, "%d", &val) == EOF) {
        fprintf(stderr, "Unexpected end of input file: Not enough values!\n");
        exit(EXIT_FAILURE);
      }
      _col_row(c, r, sudoku) = val;
    }
  }
  return sudoku;
}

void writeSudoku(FILE *fich, Sudoku sudoku) {
  for (int r=0; r<SUDOKU_SIZE; r++) {
    for (int c=0; c<SUDOKU_SIZE; c++) {
      if (fprintf(fich, "%d ", _col_row(c, r, sudoku)) < 0) {
        perror("Error writing to output file");
        exit(EXIT_FAILURE);
      }
    }
    fprintf(fich, "\n");
  }
}

void printSodoku(Sudoku sudoku) {
  writeSudoku(stdout, sudoku);
}
