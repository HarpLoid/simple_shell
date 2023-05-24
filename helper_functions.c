#include "shell.h"

/**
 * _strchr - finds a character in
 * a string.
 * @s: string to search.
 * @c: character to locate.
 *
 * Return: string from character c.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0' && *s != c)
	{
		s++;
	}
	if (*s == c)
	{
		return (s);
	}
	else
	{
		return ('\0');
	}
}

/**
 * _strdup - duplicates a string
 * to an allocated memory location.
 * @str: pointer to a string.
 *
 * Return: pointer to the location of
 * the duplicate string, NULL on failure.
 */
char *_strdup(const char *str)
{
	int i;
	char *s;

	if (str == NULL) /*Validates str in the function*/
	{
		return (NULL);
	}

	s = malloc(_strlen(str) * sizeof(char));
	if (s == NULL)
		return (NULL);

	for (i = 0; str[i] ; i++)
	{
		s[i] = str[i];
	}

	return (s);
}

/**
 * _atoi - (char *s);
 * converts a string to an integer
 * @s: string to convert
 *
 * Return: integer value.
 */
int _atoi(char *s)
{
	int sign = 1;
	int number = 0;

	while (s[0] != '\0')
	{
		if (s[0] == '-')
		{
			sign *= -1;
		}
		else if (s[0] >= '0' && s[0] <= '9')
		{
			number = (number * 10) + (s[0] - '0') * sign;
		}
		else if (number)
		{
			break;
		}
		s++;
	}
	return (number);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to old memory block
 * @old_size: size of old memory block
 * @new_size: size of reallocted memory
 *
 * Return: pointer to new memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i;

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
		{
			return (NULL);
		}
		free(ptr);
		return (new_ptr);
	}
	if (old_size == new_size)
	{
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
		{
			return (NULL);
		}
		for (i = 0; i < old_size; i++)
		{
			*((char *)new_ptr + i) = *((char *)ptr + i);
		}
		free(ptr);
	}
	return (new_ptr);
}
