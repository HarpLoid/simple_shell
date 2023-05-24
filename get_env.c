#include "shell.h"


char *get_env(const char *name)
{
	char **env = environ;
	char *position;
	size_t len;

	while (*env != NULL)
	{
		position = _strchr(*env, '=');
		if (position)
		{
			len = position - *env;
			if (_strncmp(*env, name, len) == 0)
				return (position + 1);
		}
		env++;
	}
	return (NULL);
}
