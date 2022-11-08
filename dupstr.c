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
