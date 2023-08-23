#include "main.h"
/**
 * execve_ - Function that execute the command if it exist
 * and if is valid
 * @command: String that recive the command
 * @args: arguments
 * Return: Return the status of the proccess
 *
*/
int execve_(char *command, char **args)
{
	int stado;
	char *pathi = _get_path("PATH"), *cmdpath;
	pid_t pid;
	struct stat check;

	if (stat(command, &check) == 0)
	{
		pid = fork();
		if (pid < 0)
			perror("Error");
		else if (pid == 0)
		{
			if (execve(command, args, environ) == -1)
				perror("Error");
		}
		else
			wait(&stado);
	}
	else
	{
		cmdpath = findexpath(command, pathi);
		if (stat(cmdpath, &check) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(cmdpath, args, environ) == -1)
				{
					free(cmdpath);
				}
			}
			else
				free(cmdpath), wait(&stado);
		}
		else
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
	}
	return (WEXITSTATUS(stado));
}
