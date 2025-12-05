#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5];

void *philosopher(void *num) {
    int id = *(int *)num;

    while (1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1);

        // Pick left chopstick
        sem_wait(&chopstick[id]);
        // Pick right chopstick
        sem_wait(&chopstick[(id + 1) % 5]);

        printf("Philosopher %d is eating...\n", id);
        sleep(1);

        // Put down chopsticks
        sem_post(&chopstick[id]);
        sem_post(&chopstick[(id + 1) % 5]);

        printf("Philosopher %d finished eating.\n", id);
        sleep(1);
    }
}

int main() {
    pthread_t phil[5];
    int ids[5];

    // Initialize semaphores
    for (int i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1);

    // Create philosopher threads
    for (int i = 0; i < 5; i++) {
        ids[i] = i;
        pthread_create(&phil[i], NULL, philosopher, &ids[i]);
    }

    // Join threads
    for (int i = 0; i < 5; i++)
        pthread_join(phil[i], NULL);

    return 0;
}
