#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include<pthread.h>

void * do_thread (void * data);

int main()
{
    int res,i;
    pthread_t a_thread;
    void * thread_result;


    res=pthread_create(&a_thread, NULL, do_thread,NULL);
    if(res !=0 )
    {
        perror("Thread create error");
        exit(EXIT_FAILURE);
    }
    sleep(3);

    printf("Try to cancel thread ..\n");
    res =pthread_cancel(a_thread);

    if(res != 0)
    {
        perror("thread cancel error");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for thread to finish ... \n");
    res=pthread_join(a_thread, &thread_result);
    if(res != 0)
    {
        perror("Thread waiting error");
        exit(EXIT_FAILURE);
    }
    printf("All done \n");
    exit(EXIT_SUCCESS);
}
void * do_thread(void * data)
{
    int i, res;
    res = pthread_setcancelstate (PTHREAD_CANCEL_ENABLE,NULL);

}