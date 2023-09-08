#include <assert.h>
#include <stdlib.h>
#include "line_reading.h"

enum ReadError getlines(FILE *file, char *table[], size_t *lines)
{
	assert(file != NULL);
	assert(table != NULL);
	assert(lines != NULL);

	char buf[BUF_SIZE] = "";
	size_t line_idx = 0;

	while (line_idx < *lines) {
		size_t char_idx = 0;
		int c = getc(file);

		while (c != EOF && char_idx < BUF_SIZE - 1) {
			buf[char_idx] = (char) c;
			char_idx++;
			if (c == '\n')
				break;
			c = getc(file);
		}

		buf[char_idx] = '\0';

		char *str = (char *) calloc(char_idx + 1, sizeof(char));
		if (str == NULL)
			return ERR_READ_MEM;

		char *bufp = buf;
		char *tmp = str;
		while ((*tmp++ = *bufp++) != '\0')
			;

		table[line_idx] = str;
		line_idx++;

		if (c == EOF)
			break;
	}

	if (ferror(file))
		return ERR_READ_FAILED;

	*lines = line_idx;

	return NO_READ_ERR;
}
