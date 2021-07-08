#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include<sys/shm.h>

#include"shm_com.h"

int main()
{
    int running =1;
    void *shared_memory= (void *)0;
    struct shared_use_st * shared_stuff;
    int shmid;
    //Khoi tao
    // srand((unsigned int )getpid());
    shmid = shmget ((key_t)1234, sizeof(struct shared_use_st), 0666|IPC_CREAT);
    if (shmid == -1)
    {
        fprintf(stderr, " shmeget failed\n");
        exit(EXIT_FAILURE);
    }
    shared_memory=shmat(shmid,(void *)0,0);
    if(shared_memory==(void *)-1)
    {
        fprintf(stderr,"shmat failed \n");
        exit(EXIT_FAILURE);
    }
    //xong khoi tao
    printf("Memory attached at %X\n", (int)shared_memory);
    shared_stuff=(struct shared_use_st *)shared_memory;
    shared_stuff->writen_by_you=0;
    while(running)
    {
        if (shared_stuff->writen_by_you)
        {
            printf("You wrote: %s", shared_stuff-> some_text);
            sleep(rand() % 4 );
            shared_stuff->writen_by_you=0;
            if(strncmp(shared_stuff->some_text, "end", 3)==0)
            {
                running=0;
            }
        }
    }
    //giai phong shared memory
    if(shmdt(shared_memory)==-1)
    {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }
    if(shmctl(shmid, IPC_RMID, 0)==-1)
    {
        fprintf(stderr, "shmctl (IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
//result
// ./shar1
// Memory attached at 762B1000
// You wrote: hello
// You wrote: linux!
// You wrote: end