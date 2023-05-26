#include "shell.h"

/**
 * free_tokens - frees the memory
 * of an array of strings
 * @tokens: array of string to free
 *
 * Return: void
 */
void free_tokens(char **buffer)
{
	int i;

	for (i = 0; buffer[i]; i++)
	{
		free(buffer[i]);
	}
	free(buffer);
}
