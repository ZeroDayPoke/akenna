#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int builtInRet, customRet;
	char *testMe = "dumpsterfire";
	char *add;

	add = dupstr(testMe);
	builtInRet = strlen(strdup(testMe));
	customRet = strlen(dupstr(testMe));
	printf("built in length: %d & custom length: %d\n", builtInRet, customRet);
	printf("loca of fire: %p & loca of dumpster: %p\n", testMe, add);
	return (0);
}
