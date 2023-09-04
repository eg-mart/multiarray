#define RED(str) "\033[31m" str "\033[0m"
#define GREEN(str) "\033[32m" str "\033[0m"

enum Matrix_error {
	NO_MATRIX_ERR =  0,
	ERR_WRITE	  = -1,
};

enum Matrix_error print_matrix(const int matrix[]);
int *allocate_matrix(size_t rows, size_t cols);
void multiply_matrix(const int first[], const int second[], int result[]);
int get_element(const int matrix[], size_t row_idx, size_t col_idx);
int set_element(int matrix[], size_t row_idx, size_t col_idx, int new_element);
