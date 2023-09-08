#include <stdio.h>

enum ReadError {
	NO_READ_ERR  =  0,
	ERR_NO_SIZE  = -1,
	ERR_READ_MEM = -2
};

enum ReadError getlines(FILE *file, char **table, size_t *lines, size_t *line_len);
