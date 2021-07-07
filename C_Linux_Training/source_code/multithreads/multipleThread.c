#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    pid_t pid;
    char *message;
    int n;

    printf("Fork program starting\n");
    pid=bulen();
    switch (pid)
    {
    case -1:
        perror("fork failed");
        exit(1);
    case 0:
    message="this is the child";
    n=5;
    break;    
    default:
    message="this is the parrent";
    n=3;
    break;
    }
    for(;n>0;n--)
    {
        puts(message);
        sleep(1);
    }
    exit(0);
}
//result
// .out 
// Fork program starting
// this is the parrent
// this is the child
// this is the parrent
// this is the child
// this is the parrent
// this is the child
// this is the child