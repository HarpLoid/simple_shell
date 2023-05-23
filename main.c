#include "shell.h"

/**
 * main - main program for the shell
 * @ac: 
 * @av:
 * @env:
 *
 * Return: Always 0
 */
int main(__attribute__((unused)) int ac, char *av[])
{
	char *line = NULL;
	size_t n = 0;
	char **tokens;
	
	while (1)
	{	
		if (prompt(&line, &n) == 1)
			return (1);

		tokens = tokenize(line, " ,.\t");

		if (execute(tokens, environ) == -1)
		{
			perror(av[0]);
			return(1);
		}

	}
	

	return (0);
}
