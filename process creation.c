#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if(pid < 0)
        printf("Fork failed!\n");

    else if(pid == 0)
        printf("Child Process\nPID: %d\nPPID: %d\n", getpid(), getppid());

    else
        printf("Parent Process\nPID: %d\nChild PID: %d\n", getpid(), pid);

    return 0;
}
