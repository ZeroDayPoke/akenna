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
		tokenStorage[i] = malloc(sizeof(char) * (ssLen + 2));
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

/*
ssize_t readlineSI(char **line, size_t *n, FILE *inbound)
{
	ssize_t input, ret;
	char *buffer, c = 'c';
	int retVal;

	input = 0;
	buffer = malloc(sizeof(char) * 1028);
	while (c != '\n')
	{
		retVal = read(STDIN_FILENO, &c, 1);
		if (retVal < 0)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}
		if (retVal == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 1028)
		{
			printf("BUFFER SIZE 1028 EXCEEDED");
			exit(EXIT_FAILURE);
		}
		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';
	ret = input;
	return (ret);
}
*/
