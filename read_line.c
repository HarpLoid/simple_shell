#include "shell.h"

ssize_t read_line(char **line, size_t *n, FILE *stream)
{
	ssize_t bytes_read = 0;
	size_t chars_read = 0;
	char *newline;

	if (*line == NULL && *n == 0)
	{
		*n = 64;
		*line = malloc(*n);
		if (line == NULL)
			return (-1);
	}

	while ((bytes_read = read(fileno(stream), *line + chars_read,
			*n - chars_read)) != -1)
	{
		chars_read += bytes_read;

		if ((*line)[chars_read - 1] == '\n')
			break;
		

		if (chars_read == *n)
		{
			*n *= 2;
			newline = realloc(*line, *n);
			if (newline == NULL)
			{
				free(*line);
				*line = NULL;
				return(-1);
			}
			*line = newline;
		}
	}
	(*line)[chars_read - 1] = '\0';

	return (bytes_read);
}
