#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include "stData.h"

int main()
{
    int running = 1;
    int shmid;
    char buffer[MAX_SIZE];
    struct stData *mydata;
    void *share_memory = (void *)0;
    shmid = shmget((key_t)1236, sizeof(struct stData), 0666 | IPC_CREAT);
    share_memory = shmat(shmid, (void *)0, 0);
    mydata = (struct stData *)share_memory;
    mydata->wrote = 0;
    while (running)
    {
        while (mydata->wrote)
        {
            printf("Waiting server....\n");
            sleep(1);
        }
        printf("Enter some text:");
        fgets(buffer, MAX_SIZE, stdin);
        strncpy(mydata->content, buffer, MAX_SIZE);
        mydata->wrote = 1;
        if (strncmp(mydata->content, "end", 3) == 0)
        {
            printf("Bye!");
            running = 0;
        }
    }
    shmdt(share_memory);
    shmctl(shmid,IPC_RMID,0);
}