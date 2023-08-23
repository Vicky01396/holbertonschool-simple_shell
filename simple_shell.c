#include "main.h"
/**
 * main - Main function of a the simple command interpreter
 * Return: If all work, the function should be return 0
*/
int main(void)
{
	char *buff = NULL, **str = NULL;
	size_t size;
	ssize_t read;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		read = getline(&buff, &size, stdin);
		if (read == -1)
		{
			free(buff);
			exit(0);
		}
		str = tokethis(buff);
		if (str == NULL || str[0] == NULL)
		{
			free(buff);
			continue;
		}
		if (strcmp(str[0], "exit") == 0)
		{
			break;
		}
		if (execve_(str[0], str) == -1)
		{
			continue;
		}
		free(str);
	}
	if (str)
		free_grid(str);
	return (0); /*Finish the program success*/
}
