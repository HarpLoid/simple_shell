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
	int i, size = 0;
	print("in function");
	for (i = 0; buffer[i]; i++, size++)
		;
	if (size >= 1)
	{
		for (i = 0; buffer[i] != NULL; i++)
		{
			printf("freeing %s[%d]\n", buffer[i], i);
			free(buffer[i]);
		}
	}
	free(buffer);
}
