#include <stdio.h>

const size_t BUF_SIZE = 1024;

enum ReadError {
	NO_READ_ERR		=  0,
	ERR_READ_MEM	= -2,
	ERR_READ_FAILED = -3
};

enum ReadError getlines(FILE *file, char *table[], size_t *lines);
