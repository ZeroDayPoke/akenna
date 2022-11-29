#include "main.h"

char **get_input(char *input)
{
    char **command = malloc(sizeof(char *));
    char *separator = " ";

    command = tokstr(input, separator);
    return (command);
}

int main(int argc, char *argv[], char *envp[])
{
    pid_t child_pid;
	int stat1;
	char *line = NULL, **command;
	size_t n = 0;
    const char *shell = "/usr/bin/ls";

    if (argc || argv[0])
    {
        /* placeholder */
    }
	while (getline(&line, &n, stdin) != -1)
    {
        command = get_input(line);
        child_pid = fork();
        if (child_pid == 0)
        {
            execve(shell, command, envp);
        }
        else
        {
            waitpid(child_pid, &stat1, WUNTRACED);
        }
	}
	free(line);
	free(command);
    return (0);
}
