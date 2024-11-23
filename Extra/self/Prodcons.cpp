#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <semaphore.h>

#define SHARED_MEMORY_NAME "/posix_shared_mem"
#define SEM_FULL "/sem_full"
#define SEM_EMPTY "/sem_empty"
#define SEM_MUTEX "/sem_mutex"
#define BUFFER_SIZE 10

typedef struct {
    char buffer[BUFFER_SIZE];
    int index;
} SharedData;

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// Producer function
void producer() {
    // Open shared memory
    int shm_fd = shm_open(SHARED_MEMORY_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) handle_error("shm_open");

    // Set shared memory size
    ftruncate(shm_fd, sizeof(SharedData));

    // Map shared memory
    SharedData *shared_data = mmap(0, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_data == MAP_FAILED) handle_error("mmap");

    // Open semaphores
    sem_t *sem_full = sem_open(SEM_FULL, O_CREAT, 0666, 0);
    sem_t *sem_empty = sem_open(SEM_EMPTY, O_CREAT, 0666, BUFFER_SIZE);
    sem_t *sem_mutex = sem_open(SEM_MUTEX, O_CREAT, 0666, 1);

    if (sem_full == SEM_FAILED || sem_empty == SEM_FAILED || sem_mutex == SEM_FAILED)
        handle_error("sem_open");

    // Produce data
    for (int i = 0; i < 20; i++) {
        sem_wait(sem_empty);
        sem_wait(sem_mutex);

        // Critical section
        snprintf(shared_data->buffer + shared_data->index, 2, "%c", 'A' + (i % 26));
        printf("Producer produced: %c\n", shared_data->buffer[shared_data->index]);
        shared_data->index = (shared_data->index + 1) % BUFFER_SIZE;

        sem_post(sem_mutex);
        sem_post(sem_full);

        sleep(1); // Simulate production time
    }

    // Cleanup
    munmap(shared_data, sizeof(SharedData));
    close(shm_fd);
}

// Consumer function
void consumer() {
    // Open shared memory
    int shm_fd = shm_open(SHARED_MEMORY_NAME, O_RDWR, 0666);
    if (shm_fd == -1) handle_error("shm_open");

    // Map shared memory
    SharedData *shared_data = mmap(0, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_data == MAP_FAILED) handle_error("mmap");

    // Open semaphores
    sem_t *sem_full = sem_open(SEM_FULL, 0);
    sem_t *sem_empty = sem_open(SEM_EMPTY, 0);
    sem_t *sem_mutex = sem_open(SEM_MUTEX, 0);

    if (sem_full == SEM_FAILED || sem_empty == SEM_FAILED || sem_mutex == SEM_FAILED)
        handle_error("sem_open");

    // Consume data
    for (int i = 0; i < 20; i++) {
        sem_wait(sem_full);
        sem_wait(sem_mutex);

        // Critical section
        shared_data->index = (shared_data->index - 1 + BUFFER_SIZE) % BUFFER_SIZE;
        char item = shared_data->buffer[shared_data->index];
        printf("Consumer consumed: %c\n", item);

        sem_post(sem_mutex);
        sem_post(sem_empty);

        sleep(1); // Simulate consumption time
    }

    // Cleanup
    munmap(shared_data, sizeof(SharedData));
    close(shm_fd);
}

// Main function to select producer or consumer
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [producer|consumer]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "producer") == 0) {
        producer();
    } else if (strcmp(argv[1], "consumer") == 0) {
        consumer();
    } else {
        fprintf(stderr, "Invalid argument. Use 'producer' or 'consumer'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
