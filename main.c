#include "main.h"

int main(void)
{
    pid_t child_pid = fork();

    if (child_pid == 0)
	{
        printf("### Child ###\nCurrent PID: %d and Child PID: %d\n",
               getpid(), child_pid);
    } else
	{
		sleep(1);
        printf("### Parent ###\nCurrent PID: %d and Child PID: %d\n",
               getpid(), child_pid);
    }
 
    return (0);
}
