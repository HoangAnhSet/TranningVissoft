#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/sem.h>
static int set_semvalue(void);
static int del_semvalue(void);
static int semaphore_p(void);
static int semaphore_v(void);
static int sem_id;


int main(int argc, char *argv[])
{
    int i;
    int pause_time;
    char op_char="O";
    srand((unsigned int)getpid());
    sem_id=semget((key_t)1234, 1, 0666|IPC_CREAT);
    if(argc>1){
        if(!set_semvalue())
        {
           fprintf(stderr, "Failed to initialize semaphore\n") ;
           exit(EXIT_FAILURE);
        }
        op_char='X';
        sleep(2);
    }
    for(int i=0;i<10;i++)
    {
        if(!semaphre_v()) exit(EXIT_FAILURE);
        pause_time=rand()%2;
        sleep(pause_time);
        printf("%c", op_char);fflush(stdout);
        if(!semaphore_v()) exit(EXIT_FAILURE);
        pause_time=rand()%2;
        sleep(pause_time);
    }
    printf("\n%d -finished\n", getid());]
    if(argc >1)
    {
        sleep(10);
        del_semvalue();
    }
    exit(EXIT_SUCCESS);
}
static int set_semvalue(void)
{
    unio semun sem_union;
    sem_union.val=1;
    if(semctl(sem_id, 0, SETVAL, sem_union) == -1)
    return (0);
    return (1);
}
