#include "main.h"

char **path_locate(char *envvars[])
{
	unsigned int i = 0;
	char **daWay = NULL;

	for (; envvars[i]; i++)
	{
		if (_strncmp("PATH", envvars[i], 4) == 0)
		{
			daWay = path_tok(envvars[i]);
			return (daWay);
		}
	}
	return(daWay);
}

char **path_tok(char *path)
{
	char **thePaths = malloc(sizeof(char *));
    char *separator = ":";

    thePaths = tokstr(path, separator);
	thePaths[0] += 5;
	return(thePaths);
}

void print_paths(char **pathArr)
{
	unsigned int i = 0;

	for (; pathArr[i]; i++)
	{
		printf("path %d is %s\n", i, pathArr[i]);
	}
}

int check_paths(char **pathArr, char *command)
{
	unsigned int i = 0, ret = -1;
	struct stat s;
	char *cmpPath;

	cmpPath = malloc(sizeof(char) * 101);
	for (; pathArr[i]; i++)
	{
		_strcpy(cmpPath, pathArr[i]);
		_strcat(cmpPath, "/");
		_strcat(cmpPath, command);
		if (stat(cmpPath, &s) == 0)
		{
			ret = i;
			break;
		}
	}
	return (ret);
}
