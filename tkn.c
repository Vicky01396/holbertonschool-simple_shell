#include "main.h"
/**
 * tokethis - Function that save the imput in tokens,
 * the tokens are storaged in a array.
 * @imp: Is the imput that the funciton tokenized.
 * Return: words(array whit the tokk)
*/
char **tokethis(char *imp)
{
	int i = 0;
	int countw = 0;
	char **words = NULL;

	while (imp[i] != '\0')
	{
		if (imp[i] == ' ' || imp[i] == '\t' || imp[i] == ':' || imp[i + 1] == '\n')
		{
			countw++;
		}
		i++;
	}
	countw += 1;
	printf("\nCantidad de tokens es ---> %d\n", countw);
	words = malloc((countw + 1) * sizeof(char *));
	if (words == NULL)
	{
		free(imp);
		return (NULL);
	}
	words[0] = strtok(imp, " \n\t:");
	i = 1;
	while (i < countw)
	{
		words[i] = strtok(NULL, " \n\t:");
		i++;
	}
	words[i] = NULL;
	return (words);
}
