#include <stdlib.h>
#include <stdio.h>

#include "io.h"
#include "main.h"

Sudoku readSudoku(FILE* file) {
  Sudoku sudoku;
  Digit val;
  for (int i=0; i<SUDOKU_SIZE; i++) {
    for (int j=0; j<SUDOKU_SIZE; j++) {
      if (fscanf(file, "%d", &val) == EOF) {
        fprintf(stderr, "Unexpected end of input file: Not enough values!\n");
        exit(EXIT_FAILURE);
      }
      dref_(sudoku, i, j) = val;
    }
  }
  return sudoku;
}

void writeSudoku(FILE *fich, Sudoku sudoku) {
  for (int i=0; i<SUDOKU_SIZE; i++) {
    for (int j=0; j<SUDOKU_SIZE; j++) {
      if (fprintf(fich, "%d ", dref_(sudoku, i, j)) < 0) {
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
