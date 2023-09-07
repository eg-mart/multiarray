#include <assert.h>
#include "line_reading.h"

size_t getlines(FILE *file, char *table, size_t lines, size_t line_len)
{
	assert(file != NULL);
	assert(table != NULL);

	size_t line_idx = 0;

	while (line_idx < lines) {
		size_t char_idx = 0;
		int c = getc(file);

		while (c != EOF && char_idx < line_len - 1) {
			table[line_idx * line_len + char_idx] = (char) c;
			char_idx++;
			if (c == '\n')
				break;
			c = getc(file);
		}

		table[line_idx * line_len + char_idx] = '\0';
		line_idx++;

		if (c == EOF)
			break;
	}

	return line_idx;
}
