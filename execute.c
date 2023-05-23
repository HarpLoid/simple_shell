#include "shell.h"

/**
 *
 */
int execute(char **buffer, char **environ)
{
	int child_pid;
	
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error with forking");
		return (1);
	}

	if (child_pid == 0)
	{
		if (execve(buffer[0], buffer, environ) == -1)
		{
			perror("Error with executing");
			return (1);
		}
		return (0);
	}
	else
	{
		wait(NULL);
	}

	return (0);
}
