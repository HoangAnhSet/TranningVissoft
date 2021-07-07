#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <string.h>
#include <pthread.h>

#include <semaphore.h>

void *thread_function(void *arg);
pthread_mutex_t work_mutex;

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;
int main()
{
    int res;
    pthread_t a_thread;
    void *thread_result;
    res = pthread_mutex_init(&work_mutex, NULL);
    if (res != 0)
    {
        perror("Mutex initialization failed");
        exit(EXIT_FAILURE);
    }
    res=pthread_create(&a_thread,NULL, thread_function,NULL);
    if(res !=0 )
    {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_lock(&work_mutex);
    printf("Input some text. Enter 'end' to finish\n");
    while(!time_to_exit)
    {
        fgets()
    }
    pthread_mutex_lock
}