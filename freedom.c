#include "main.h"

void free_tokens(char **tokens)
{
	unsigned int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
