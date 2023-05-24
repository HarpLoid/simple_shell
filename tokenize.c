#include "shell.h"

/**
 * isdelim - checks if the char is a delimiter
 */
int isdelim(char c, const char *delim)
{
	int i;

	for (i = 0; delim[i]; i++)
	{
		if (c == delim[i])
			return (1);
	}
	return (0);
}

char **tokenize(char *buffer, const char *delim)
{
	char **result = NULL;
	int result_size = 0, buffer_size = _strlen(buffer), len = 0, start = 0, end = 0;

	while (end < buffer_size && buffer[end] != '\0')
	{
		if (isdelim(buffer[end], delim) || end == buffer_size - 1)
		{
			if (end == buffer_size -1)
				len = (end - start) + 1;
			else
				len = end - start;

			if (len > 0)
			{
				result = realloc(result, (result_size + 1) * sizeof(char*));
				if (result == NULL)
				{
					free(result);
					return (NULL);
				}
				result[result_size] = malloc((len + 1) * sizeof(char));
				if (result[result_size] == NULL)
				{
					free(result[result_size]);
					return(NULL);
				}
				
				_strncpy(result[result_size], buffer + start, len);
				result[result_size][len] = '\0';
				result_size++;
			}
			start = end + 1;
		}
		end++;
	}
	result[result_size] = NULL;
	return (result);
}

