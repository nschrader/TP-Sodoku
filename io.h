#ifndef IO_H
#define IO_H

#include "main.h"

Sudoku readSudoku(FILE* file);
void writeSudoku(FILE *fich, Sudoku sudoku);
void printSodoku(Sudoku sudoku);

#endif
