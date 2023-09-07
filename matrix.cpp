#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

enum Matrix_error print_matrix(const struct Matrix *matrix)
{
	assert(matrix != NULL);

	for (size_t row_idx = 0; row_idx < matrix->rows; row_idx++) {
		for (size_t col_idx = 0; col_idx < matrix->cols; col_idx++)
			printf("%3d\t", get_element(matrix, row_idx, col_idx));
		printf("\n");
	}

	if (ferror(stdout))
		return ERR_WRITE;
	return NO_MATRIX_ERR;
}

void multiply_matrix(const struct Matrix *first, const struct Matrix *second,
					 struct Matrix *result)
{
	assert(first  != NULL);
	assert(second != NULL);
	assert(result != NULL);
	assert(first->cols == second->rows);

	result->rows = first->rows;
	result->cols = second->cols;

	for (size_t row_idx = 0; row_idx < first->rows; row_idx++) {
		for (size_t col_idx = 0; col_idx < second->cols; col_idx++) {
			int product = 0;
			for (size_t i = 0; i < first->cols; i++)
				product += get_element(first, row_idx, i) *
						   get_element(second, i, col_idx);
			set_element(result, row_idx, col_idx, product);
		}
	}
}

enum Matrix_error allocate_matrix(struct Matrix *matrix)
{
	assert(matrix != NULL);

	matrix->data = (int*) calloc(matrix->rows * matrix->cols, sizeof(int));
	if (matrix->data == NULL)
		return ERR_MEM;
	return NO_MATRIX_ERR;
}

int get_element(const struct Matrix *matrix, size_t row_idx, size_t col_idx)
{
	assert(row_idx < matrix->rows);
	assert(col_idx < matrix->cols);

	return *((int*) ((size_t) matrix->data + sizeof(int) * (row_idx * matrix->cols + col_idx)));
}

int set_element(struct Matrix *matrix, size_t row_idx, size_t col_idx, int new_element)
{
	assert(row_idx < matrix->rows);
	assert(col_idx < matrix->cols);

	int old = get_element(matrix, row_idx, col_idx);
	matrix->data[row_idx * matrix->cols + col_idx] = new_element;
	return old;
}