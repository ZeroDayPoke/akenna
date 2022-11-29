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
	int stat1, eRet = 0;
	char *line = NULL, **command = NULL, *moneySign;
	size_t n = 0;
    struct stat s;
    char *theWay = "/usr/bin/", *thePath;

    moneySign = "$ ";
    if (argc || argv[0] || thePath)
    {
        /* placeholder */
    }
    thePath = malloc(sizeof(char) * 101);
	while (1)
    {
        write(STDOUT_FILENO, moneySign, 2);
        eRet = getline(&line, &n, stdin);
        if (eRet == -1)
        {
            break;
        }
        command = get_input(line);
        _strcpy(thePath, theWay);
        _strcat(thePath, command[0]);
        if (stat(thePath, &s) != 0)
        {
            printf("./hsh: %s not found\n", command[0]);
            continue;
        }
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
    write(STDOUT_FILENO, "\n", 1);
    free(thePath);
    if (command != NULL)
    {
        free_tokens(command);
        free(command);
    }
    return (0);
}
