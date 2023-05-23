#include "shell.h"

/**
 *
 */
int prompt(char **line, size_t *n)
{
	char *prompt = "$ ";

	if (write(STDOUT_FILENO, prompt, _strlen(prompt)) == -1)
		return (1);
	

	if (read_line(line, n, stdin) == -1)
		return (1);


	return (0);
}
