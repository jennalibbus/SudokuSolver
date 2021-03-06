// Solver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define SUDOKU_SIZE 9
#define DEBUG

char sudoku[SUDOKU_SIZE*SUDOKU_SIZE] = { 1, 4, 2, 3, 6, 5, 7, 8, 9, 6, 8, 7, 1, 4, 9, 2, 5, 3, 5, 3, 9, 7, 8, 2, 6, 1, 4, 4, 1, 3, 6, 7, 8, 5, 9, 2, 8, 7, 5, 2, 9, 3, 1, 4, 6, 2, 9, 6, 4, 5, 1, 3, 7, 8, 9, 6, 1, 8, 2, 7, 4, 3, 5, 7, 5, 4, 9, 3, 6, 8, 2, 1, 3, 2, 8, 5, 1, 4, 9, 6, 7 };
void check_col(char col);
void check_box(char box);
void check_row(char row);

int main()
{
	char row_num, col_num, box_num;
	// row indicates the row number being analyzed, from 0-8
	// col indicates the column number being analyzed, from 0-8
	// box indicates the 3 by 3 box being analyzed, box 0 is top left, box 1 is top middle, box 2 is top right, etc
	
	check_box(6);

	return 0;
}

void check_row(char row) {
	char new_array[SUDOKU_SIZE];
	int i;

	for (i = 0; i < 9; i++) {
		new_array[i] = sudoku[row*9 + i];
	}

#ifdef DEBUG
	printf(" %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d", new_array[0], new_array[1], new_array[2], new_array[3], new_array[4], new_array[5], new_array[6], new_array[7], new_array[8]);
	getchar();
#endif // DEBUG

}

void check_col(char col) {
	char new_array[SUDOKU_SIZE];
	int i;

	for (i = 0; i < 9; i++) {
		new_array[i] = sudoku[col + i * 9];
	}

#ifdef DEBUG
	printf(" %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d", new_array[0], new_array[1], new_array[2], new_array[3], new_array[4], new_array[5], new_array[6], new_array[7], new_array[8]);
	getchar();
#endif // DEBUG

}

void check_box(char box) {
	char new_array[SUDOKU_SIZE];
	int i, j, offset;

	if (box < 3)
		offset = 0;
	else if (box < 6)
		offset = 18;
	else
		offset = 36;

	for (j = 0; j < 3; j++) {
		for (i = 0; i < 3; i++) {
			new_array[i + 3*j] = sudoku[box * 3 + i + offset + j*9];
		}
	}

#ifdef DEBUG
	printf(" %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d", new_array[0], new_array[1], new_array[2], new_array[3], new_array[4], new_array[5], new_array[6], new_array[7], new_array[8]);
	getchar();
#endif // DEBUG

}

