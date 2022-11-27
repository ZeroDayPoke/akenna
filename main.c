#include "main.h"

int main(void)
{
    pid_t child_pid, hold_up;
	int stat1;
	char *argv[] = {"ls", "-l", "-h", "-a", NULL};

	execvp(argv[0], argv);
	child_pid = fork();
    if (child_pid == 0)
	{
        printf("### Child ###\nCurrent PID: %d and Child PID: %d\n",
               getpid(), child_pid);
		sleep(1);
    }
	else
	{
		hold_up = waitpid(child_pid, &stat1, WUNTRACED);
		if (hold_up)
			printf("SUCCESSFUL HOLD\n");
        printf("### Parent ###\nCurrent PID: %d and Child PID: %d\n",
               getpid(), child_pid);
    }
    return (0);
}
