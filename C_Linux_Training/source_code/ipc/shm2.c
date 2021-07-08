#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/shm.h>

#include "shm_com.h"

int main()
{
    int running = 1;
    void *shared_memory = (void *)0;
    struct shared_use_st *shared_stuff;
    char buffer[BUFSIZ];
    int shmid;
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);

    if (shmid == -1)
    {
        fprintf(stderr, "shmet failed!\n");
        exit(EXIT_FAILURE);
    }
    shared_memory = shmat(shmid, (void *)0, 0);
    if (shared_memory == (void *)-1)
    {
        fprintf(stderr, "shmat failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %X\n", (int)shared_memory);
    shared_stuff = (struct shared_use_st *)shared_memory;
    while (running)
    {
        while (shared_stuff->writen_by_you == 1)
        {
            sleep(1);
            printf("Waiting for client...\n");
        }
        printf("Enter some text:");
        fgets(buffer,BUFSIZ,stdin);
        strncpy(shared_stuff->some_text,buffer,TEXT_SZ);
        shared_stuff->writen_by_you=1;
        
    }
    exit(EXIT_SUCCESS);
}