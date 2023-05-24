#include "shell.h"

/**
 * free_tokens - frees the memory
 * of an array of strings
 * @tokens: array of string to free
 *
 * Return: void
 */
void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i]; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
