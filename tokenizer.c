#include "main.h"

int tok_num(char *str, char *delims)
{
	int tokTotal = 0, i, tokLen = 0;

	for (i = 0; str[i]; i++)
	{
		tokLen++;
	}
	for (i = 0; i < tokLen; i++)
	{
		if (str[i] != *delims)
		{
			tokTotal++;
			i += substrLen(str + i, delims);
		}
	}
	return (tokTotal);
}

int substrLen(char *str, char *delims)
{
	int i = 0, tokLen = 0;

	while (str[i] && str[i] != *delims)
	{
		i++;
		tokLen++;
	}
	return (tokLen);
}

char **tokstr(char *line, char *delims)
{
	char **tokenStorage;
	int i, j, k, tokTotal, ssLen;

	tokTotal = tok_num(line, delims);
	tokenStorage = malloc(sizeof(char *) * (tokTotal + 1));
	for (i = 0; i < tokTotal; i++)
	{
		while (line[j] == *delims)
			j++;
		ssLen = substrLen(line + j, delims);
		tokenStorage[i] = malloc(sizeof(char) * (ssLen + 1));
		for (k = 0; k < ssLen; k++)
		{
			if (line[j] != '\n')
			{
				tokenStorage[i][k] = line[j];
				j++;
			}
		}
		tokenStorage[i][k] = '\0';
	}
	tokenStorage[i] = NULL;
	return (tokenStorage);
}
