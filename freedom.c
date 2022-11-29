#include "main.h"

/**
 * free_tokens - frees mem assoc w indv strs in strarr
 * @tokens: array of str tokens
 * Return: void
 */
void free_tokens(char **tokens)
{
	unsigned int i = 0;

	for (; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
}
