#include <stdlib.h>
#include <stdio.h>

#include "main.h"
#include "io.h"

static char* getFileNameFromArgumets(int argc, char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s file\n", argv[0]);
    exit(EXIT_FAILURE);
  }
	return argv[1];
}

FILE* openFileAndCheck(char *fileName) {
	FILE* file = fopen(fileName, "r");
	if (file == NULL) {
		perror("Cannot open input file");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char* argv[]) {
	char* fileName = getFileNameFromArgumets(argc, argv);
	FILE* file = openFileAndCheck(fileName);
  Sudoku sudoku = readSudoku(file);
	printSodoku(sudoku);
	return EXIT_SUCCESS;
}
