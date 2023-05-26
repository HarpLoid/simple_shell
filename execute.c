#include "shell.h"

/**
 * execute - executes the commands in buffer
 * @buffer: buffer containing commands
 * @environ: enviroment
 *
 * Return: 0 on success, 1 on error
 */
int execute(char **buffer)
{
	pid_t pid;
	int status, found;

	if (access(buffer[0], F_OK) != 0)
	{
		found = _which(buffer);
		/*find full path*/
		if (found == 1)
		{
			free_tokens(buffer);
			return (1);
		}
	}

	if (access(buffer[0], X_OK) == 0)
	{
		print("is executable");
		pid = fork();
		if (pid == -1)
		{
			perror("Error with forking");
			return (1);
		}

		if (pid == 0)
		{
			print("executing");
			if (execve(buffer[0], buffer, environ) == -1)
			{
				free_tokens(buffer);
				return (-1);
			}
		}
	}
	wait(&status);
	free_tokens(buffer);
	
	return (0);
}
