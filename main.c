#include "main.h"

char **get_input(char *input)
{
    char **command = malloc(sizeof(char *));
    char *separator = " ";

    command = tokstr(input, separator);
    return (command);
}

int main(int argc, char *argv[])
{
    pid_t child_pid;
	int stat1;
	char *line = NULL, **command;
	FILE *inbound = NULL;
	size_t n = 0;

    if (argc != 2)
    {
        exit(EXIT_FAILURE);
    }
    inbound = fopen(argv[1], "r");
	while (getline(&line, &n, inbound) != -1)
    {
        command = get_input(line);
        child_pid = fork();
        if (child_pid == 0)
        {
            /* Never returns if the call is successful */
            printf("%s", command[0]);
            execvp(command[0], command);
            printf("This won't be printed if execvp is successul\n");
        }
        else
        {
            waitpid(child_pid, &stat1, WUNTRACED);
        }
	}
    fclose(inbound);
	free(line);
	free(command);
    return (0);
}
