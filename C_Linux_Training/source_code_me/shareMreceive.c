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
    struct stData *mydata;
    void *share_memory = (void *)0;
    shmid = shmget((key_t)1236, sizeof(struct stData), 0666 | IPC_CREAT);
    share_memory = shmat(shmid, (void *)0, 0);
    mydata = (struct stData *)share_memory;
    while (running)
    {
        if (mydata->wrote)
        {
            printf("Your content:%s", mydata->content);
            mydata->wrote = 0;
        }
        if (strncmp(mydata->content, "end", 3) == 0)
        {
            printf("Bye!");
            running = 0;
        }
    }
    shmdt(share_memory);
}