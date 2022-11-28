#include "main.h"

/**
 * dupstr - This function duplicates a string (char *fire)
 * and stores it in a newly allocated block of memory. It
 * then returns a pointer to that new memory block.
 *
 * The name is wildly appropriate when you think about it.
 *
 * @fire: pointer to string to duplicate
 *
 * Return: pointer to duplicated string hextek location
 *
 */
char *dupstr(char *fire)
{
	unsigned int i = 0;
	char *dumpster;

	/* mitigate bad magic */
	if (!(fire))
	{
		return (NULL);
	}

	/* gets strlen */
	while (fire[i])
	{
		i++;
	}

	/* find a good location in memory and check */
	dumpster = malloc(sizeof(char) * (i + 1));
	if (!(dumpster))
	{
		return (NULL);
	}

	/* copy the string contents */
	for (i = 0; fire[i]; i++)
	{
		dumpster[i] = fire[i];
	}
	dumpster[i] = '\0';

	/* return new string loca */
	return (dumpster);
}

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
	tokenStorage = malloc(sizeof(char *) * tokTotal);
	for (i = 0; i < tokTotal; i++)
	{
		while (line[j] == *delims)
			j++;
		ssLen = substrLen(line + j, delims);
		tokenStorage[i] = malloc(sizeof(char) * (ssLen + 1));
		for (k = 0; k < ssLen; k++)
		{
			tokenStorage[i][k] = line[j];
			j++;
		}
		tokenStorage[i][k] = '\0';
	}
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
