#include "main.h"
/**
 * _get_path - This function find the envirion variable called PATH
 *  save and return the PATH variable.
 * @env: String to compare whit the environ variable.
 * Return: the volue of the PATH or NULL.
*/
char *_get_path(const char *env)
{
	int i = 0;
	size_t length = strlen(env);
	char *current_env = NULL;

	for (; environ[i] != NULL; i++)
	{
		current_env = environ[i];
		if (strncmp(current_env, env, length) == 0)
		{
			return (&current_env[length + 1]);
		}
	}
	return (NULL);
}
/**
 * findexpath - This function find the command in every path direction
 * @command: This is the command that the function read
 * @path: Is the copy of the original PATH
 * Return: The direction of the command in the PATH or 0
*/
char *findexpath(const char *command, char *path)
{
	char *pathcpy = strdup(path);
	char **token = NULL;
	char commandpath[1024];
	int i = 1;

	token = tokethis(pathcpy);
	while (token[i] != NULL)
	{
		sprintf(commandpath, "%s/%s", token[i], command);
		if (access(commandpath, X_OK) == 0)
		{
			free(pathcpy);
			free(token);
			return (strdup(commandpath));
		}
		else
		{
			i++;
		}
	}
	free(pathcpy);
	if (token)
		free_grid(token);
	return (NULL);
}
