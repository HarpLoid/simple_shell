#include "shell.h"

/**
 *
 */
int _which(char **str)
{
	char *path, **dir_tokens, *s = NULL;
	int i = 0;

	print("I reach here");
	path = get_env("PATH");
	print("got path");
	dir_tokens = tokenize(path, ":");
	print("gotten tokens");
	print_array(dir_tokens);

	while (dir_tokens[i])
	{
		print("looping through tokens");
		free (s);

		print("after freeing s");
		if (dir_tokens[i][0] == '\0')
		{
			print("getting current path");
			s = getcwd(NULL, 0);
		}
		else
			s = _strdup(dir_tokens[i]);
		print("after getting path");

		s = _strcat(s, "/");
		s = _strcat(s, (*str));
		if(access(s, F_OK) == 0)
		{
			(*str) = s;
			free_tokens(dir_tokens);
			return (0);
		}
		i++;
	}
	free_tokens(dir_tokens);
	return (1);
}
