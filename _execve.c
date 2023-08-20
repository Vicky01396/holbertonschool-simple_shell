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
	int stado = 0;
	char *pathi = _get_path("PATH"), *cmdpath;
	pid_t pid, child;
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
		pid = fork(), cmdpath = findexpath(command, pathi);
		printf("\n-----2----\n");
		if (pid == 0)
		{
			child = getpid();
			if (execve(cmdpath, args, environ) == -1)
			{
				fprintf(stderr, "hsh: 1: %s: not found\n", args[0]);
				free(cmdpath);
				kill(child, SIGTERM);
			}
		}
		else
		{
			free(cmdpath);
			wait(&stado);
		}
	}
	return (WEXITSTATUS(stado));
}
