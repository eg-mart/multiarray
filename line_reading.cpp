#include <assert.h>
#include <stdlib.h>
#include "line_reading.h"

enum ReadError getlines(FILE *file, char **table, size_t *lines, size_t *line_len)
{
	assert(file != NULL);
	assert(table != NULL);

	if (*table == NULL) {
		size_t tmp_lines = 0;
		size_t tmp_line_len = 0;

		int read = fscanf(file, "%lu %lu ", &tmp_lines, &tmp_line_len);
		if (read != 2)
			return ERR_NO_SIZE;

		*lines = tmp_lines;
		*line_len = tmp_line_len;

		*table = (char *) calloc((*lines) * (*line_len), sizeof(char));
		if (*table == NULL)
			return ERR_READ_MEM;
	}

	size_t line_idx = 0;

	while (line_idx < *lines) {
		size_t char_idx = 0;
		int c = getc(file);

		while (c != EOF && char_idx < *line_len - 1) {
			(*table)[line_idx * (*line_len) + char_idx] = (char) c;
			char_idx++;
			if (c == '\n')
				break;
			c = getc(file);
		}

		(*table)[line_idx * (*line_len) + char_idx] = '\0';
		line_idx++;

		if (c == EOF)
			break;
	}

	*lines = line_idx;

	return NO_READ_ERR;
}
