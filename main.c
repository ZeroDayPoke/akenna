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
	int stat1, badRet = 0;
	char *line = NULL, **command, *moneySign;
	size_t n = 0;
    char *theWay = "/usr/bin/", *thePath;

    moneySign = "$ ";
    if (argc || argv[0] || thePath)
    {
        /* placeholder */
    }
    thePath = malloc(sizeof(char) * 101);
	while (badRet != -1)
    {
        write(STDOUT_FILENO, moneySign, 2);
        badRet = getline(&line, &n, stdin);
        if (badRet == -1)
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }
        command = get_input(line);
        _strcpy(thePath, theWay);
        _strcat(thePath, command[0]);
        child_pid = fork();
        if (child_pid == 0)
        {
            execve(thePath, command, envp);
        }
        else
        {
            waitpid(child_pid, &stat1, WUNTRACED);
        }
	}
    free(thePath);
    free_tokens(command);
    return (0);
}
