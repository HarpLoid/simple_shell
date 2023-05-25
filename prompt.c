#include "shell.h"

/**
 * prompt - displays a prompt and
 * reads input from stdin, breaks inputs
 * into tokens by delimiter
 * @line: buffer to read inputs to.
 * @n: size of line buffer.
 * @tokens: string gotten from line buffer
 *
 * Return: 0 on success and 1 on failure
 */
int prompt(char **line, size_t *n, char ***tokens)
{
	char *prompt = "$ ";
	const char *delim = " ";

	if (write(STDOUT_FILENO, prompt, _strlen(prompt)) == -1)
		return (1);
	

	if (read_line(line, n, stdin) == -1)
		return (1);

	(*tokens) = tokenize((*line), delim);


	return (0);
}
