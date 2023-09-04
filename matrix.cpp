#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

enum Matrix_error print_matrix(const int matrix[])
{
	assert(matrix != NULL);

	for (size_t row_idx = 0; row_idx < matrix[0]; row_idx++) {
		for (size_t col_idx = 0; col_idx < matrix[1]; col_idx++)
			printf("%3d\t", get_element(matrix, row_idx, col_idx));
		printf("\n");
	}

	if (ferror(stdout))
		return ERR_WRITE;
	return NO_MATRIX_ERR;
}

void multiply_matrix(const int first[], const int second[], int result[])
{
	assert(first != NULL);
	assert(second != NULL);
	assert(result != NULL);
	assert(first[1] == second[0]);

	result[0] = first[0];
	result[1] = second[1];

	for (size_t row_idx = 0; row_idx < first[0]; row_idx++) {
		for (size_t col_idx = 0; col_idx < second[1]; col_idx++) {
			int product = 0;
			for (size_t i = 0; i < first[1]; i++)
				product += get_element(first, row_idx, i) *
						   get_element(second, i, col_idx);
			set_element(result, row_idx, col_idx, product);
		}
	}
}

int *allocate_matrix(size_t rows, size_t cols)
{
	int *res = (int*) calloc(rows * cols + 2, sizeof(int));
	res[0] = rows;
	res[1] = cols;
	return res;
}

int get_element(const int matrix[], size_t row_idx, size_t col_idx)
{
	assert(row_idx < matrix[0]);
	assert(col_idx < matrix[1]);
	assert(matrix != NULL);

	return matrix[row_idx * matrix[1] + col_idx + 2];
}

int set_element(int matrix[], size_t row_idx, size_t col_idx, int new_element)
{
	assert(row_idx < matrix[0]);
	assert(col_idx < matrix[1]);
	assert(matrix != NULL);

	int old = get_element(matrix, row_idx, col_idx);
	matrix[row_idx * matrix[1] + col_idx + 2] = new_element;
	return old;
}