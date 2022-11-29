#include "main.h"

/**
 * main - Entry point for ghost
 * @argc: arg count
 * @argv: array of input arg strings
 * @envp: array of inherited environment vars
 * Return: TBD
 */
int main(int argc, char *argv[], char *envp[])
{
    pid_t child_pid;
	int stat1, eRet = 0, i = 0, pathNo = 0;
	char *line = NULL, **command = NULL, *moneySign;
	size_t n = 0;
    char *thePath, **pathArr;

    moneySign = "$ ";
    pathArr = path_locate(envp);
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
        pathNo = check_paths(pathArr, command[0]);
        if (_strcmp("exit", command[0]) == 0)
        {
            break;
        }
        if (_strcmp("env", command[0]) == 0)
        {
            for (i = 0; envp[i]; i++)
            {
                printf("%s\n", envp[i]);
            }
        }
        if (pathNo == -1)
        {
            printf("./hsh: %s not found\n", command[0]);
            continue;
        }
        _strcpy(thePath, pathArr[pathNo]);
        _strcat(thePath, "/");
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
    write(STDOUT_FILENO, "\n", 1);
    free(thePath);
    if (command != NULL)
    {
        free_tokens(command);
        free(command);
    }
    return (0);
}
