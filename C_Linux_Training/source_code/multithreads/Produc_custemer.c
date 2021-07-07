#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int product_val = 2;
sem_t semaphore;

void * do_thread(void *data);
int main()
{
    int res, i;
    pthread_t a_thread;
    void *thread_result;
    res = sem_init(&semaphore, 0, 0);
    if (res != 0)
    {
        perror("Semaphore init error");
        exit(EXIT_FAILURE);
    }
    //Khoiwr taoj tuyen nguoi tieu dung
    res=pthread_create(&a_thread, NULL, do_thread,NULL);
    if(res != 0)
    {
        perror("Thread create error");
        exit(EXIT_FAILURE);
    }
    //khoi tao tuyen nguoi san xuat
    printf("Finish inition\n");
    for( i=0;i<5;i++)
    {
        product_val++;
        printf("Producer product_val= %d \n\n", product_val);
        sem_post(&semaphore);
        sleep(2);
    }
    printf("All done \n");
    exit(EXIT_SUCCESS);
}


void * do_thread(void *data)
{
    
    while(1){
    sem_wait(&semaphore);
    printf("Consumer thread function is running ..\n");
    product_val--;
    printf("Consumer product_val=%d \n",product_val);
    sleep(1);
    }
    pthread_exit(NULL);
}
