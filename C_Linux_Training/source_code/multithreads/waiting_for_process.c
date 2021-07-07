#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    char *message;
    int n;
    int exit_code;
    printf("ford program starting\n");
    pid = fork();
    switch (pid)
    {
    case -1:
        perror("fork failed");
        exit(1);
    case 0:
        message = "this is the child";
        n = 5;
        exit_code = 37;
        break;
    default:
        message = "this is the parent";
        n = 3;
        exit_code = 0;
        break;
    }

    for (; n > 0; n--)
    {
        puts(message);
        sleep(1);
    }
    if (pid != 0)
    {
        int stat_val;
        pid_t child_pid;
        child_pid = wait(&stat_val);
        printf("Child has finished: PID=%d\n", child_pid);
        if (WIFEXITED(stat_val))
            {
                printf("Child exited with code %d\n", exit_code);
            
            }
        else
        {
            printf("Child terminated abnormally\n");
        }
        exit(exit_code);
    }
}
//result
// ford program starting
// this is the parent
// this is the child
// this is the parent
// this is the child
// this is the parent
// this is the child
// this is the child
// this is the child
// Child has finished: PID=35456
// Child exited with code 0
// Parent has finished: PID=35456