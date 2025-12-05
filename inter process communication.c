#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>   // <-- REQUIRED for wait()

int main() {
    // Generate unique key
    key_t key = ftok("shmfile", 65);

    // Create shared memory (1024 bytes)
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Attach shared memory
    char *shared_data = (char *) shmat(shmid, NULL, 0);

    int pid = fork();

    if (pid == 0) {
        // Child Process: Write data
        strcpy(shared_data, "Hello from Child using Shared Memory!");
        printf("Child wrote data to shared memory.\n");

        // Detach
        shmdt(shared_data);
    } 
    else {
        // Parent Process
        wait(NULL);  // <-- line 29 fixed by adding <sys/wait.h>

        printf("Parent reads: %s\n", shared_data);

        // Detach
        shmdt(shared_data);

        // Destroy shared memory
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
