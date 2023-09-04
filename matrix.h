#define RED(str) "\033[31m" str "\033[0m"
#define GREEN(str) "\033[32m" str "\033[0m"

struct Matrix {
	int *data;
	size_t rows;
	size_t cols;
};

enum Matrix_error {
	NO_MATRIX_ERR =  0,
	ERR_MEM 	  = -1,
	ERR_WRITE	  = -2,
};

enum Matrix_error print_matrix(const struct Matrix *matrix);
enum Matrix_error allocate_matrix(struct Matrix *matrix);
void multiply_matrix(const struct Matrix *first, const struct Matrix *second, 
					 struct Matrix *result);
void add_matrix(const struct Matrix *first, const struct Matrix *second,
				struct Matrix *result);
int get_element(const struct Matrix *matrix, size_t row_idx, size_t col_idx);
int set_element(struct Matrix *matrix, size_t row_idx, size_t col_idx, int new_element);
