#include "shell.h"

/**
 * _strcpy - copies the string in
 * src to dest.
 * @src: string to copy.
 * @dest: string to be copied to.
 *
 * Return: the string in dest
 */
char *_strcpy(char *dest, char *src)
{
	int n = 0;

	while (*(src + n))
	{
		*(dest + n) = *(src + n);
		n++;
	}
	*(dest + n) = '\0';

	return (dest);
}


/**
 * _strncpy - copies the string in
 * src to dest to the nth character.
 * @src: string to copy.
 * @dest: string to be copied to.
 * @n: number of characters to copy
 *
 * Return: the string in dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strlen - finds the length of a string
 * @s: pointer to character string
 *
 * Return: value of length of string.
 */
int _strlen(const char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}

	return (count);
}

/**
 * _strcmp - compares two strings
 * and checks if they are equal.
 * @s1: first string to compare.
 * @s2: string to compare.
 *
 * Return: 0 when strings are equal
 * negative or positive when unequal.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}

	}
	return (s1[i] - s2[i]);
}

/**
 * _strncmp - compares two strings
 * and checks if they are equal to n bytes.
 * @s1: first string to compare.
 * @s2: string to compare.
 * @n: number of bytes to compare
 *
 * Return: 0 when strings are equal
 * negative or positive when unequal.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; (s1[i] || s2[i]) && i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	if (i == n)
		return (0);

	return (s1[i] - s2[i]);
}
