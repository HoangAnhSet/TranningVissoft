#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


#include<pthread.h>
void *thread_funtion(void * arg);
char message[]="Hello joined thread2 !";
int main()
{   
    pthread_t a_thread;
    void *thread_result;
    
    pthread_create(&a_thread,NULL,thread_funtion,(void *)message);
  
    // pthread_join(a_thread,&thread_result);
    //   printf("start\n");
    for(int i=0;i<10;i++)
    {
        printf("This is thread 1\n");
        sleep(1);
    }
    exit(EXIT_SUCCESS);

}
void *thread_funtion(void * arg)
{
    printf("%s",(char *)arg);
    for(int i=0;i<15;i++)
    {
        printf("This is thread 2\n");
        sleep(1);
    }
    pthread_exit("Finish success!");
}