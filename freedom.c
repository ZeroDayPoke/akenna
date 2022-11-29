#include "main.h"

void free_tokens(char **tokens)
{
	unsigned int i = 0;

	for (; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
