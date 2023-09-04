#include <stdio.h>
#include <assert.h>
#include "matrix.h"
#include <stdlib.h>

#define RED(str) "\033[31m" str "\033[0m"
#define GREEN(str) "\033[32m" str "\033[0m"

void print_table(char *str, size_t rows, size_t cols);
void print_triangle(int *arr, size_t rows);

const size_t COLS = 5;
const size_t ROWS = 5;

int main()
{
	char str[ROWS][COLS] = { "abcd", "ef", "ghi", "jklm", "n" };
	puts(GREEN("printing table:"));
	print_table(*str, ROWS, COLS);

	int arr[] = {0,
				 1, 2,
				 3, 4, 5,
				 6, 7, 8, 9,
				 10, 11, 12, 13, 14};
	puts(GREEN("\nprinting triangle table:"));
	print_triangle(arr, ROWS);

	struct Matrix matrix = { NULL, 3, 3 };
	int data[3][3] = { { 1, 2, 3 },
					   { 4, 5, 6 },
					   { 7, 8, 9 } };
	matrix.data = *data;

	puts(GREEN("\nprinting a matrix:"));
	print_matrix(&matrix);

	struct Matrix res = { NULL, 3, 3 };
	allocate_matrix(&res);
	multiply_matrix(&matrix, &matrix, &res);

	puts(GREEN("\nprinting matrix product:"));
	print_matrix(&res);
	free(res.data);
	
	return 0;
}

void print_table(char *str, size_t rows, size_t cols)
{
	assert(str != NULL);

	for (size_t row_idx = 0; row_idx < rows; row_idx++) {
		for (size_t col_idx = 0; col_idx < cols; col_idx++)
			printf(RED("%c") " %3d\t", *(str + cols * row_idx + col_idx),
				   *(str + rows * row_idx + col_idx));
		printf("\n");
	}
}

void print_triangle(int *arr, size_t rows)
{
	assert(arr != NULL);

	size_t cols = 1;
	for (size_t row_idx = 0; row_idx < rows; row_idx++) {//TODO
		for (size_t col_idx = 0; col_idx < cols; col_idx++)
			printf("%d ", *(arr + cols * (cols - 1) / 2 + col_idx));
		cols++;
		printf("\n");
	}
}
