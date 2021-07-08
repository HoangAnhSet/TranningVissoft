#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/msg.h>

#define MAX_SIZE 512

struct msg_send
{
    long int type;
    char text[MAX_SIZE];
};
int main()
{
    int running = 1;
    struct msg_send mystruct;
    char buffer[BUFSIZ];
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    // khai tao message queue
    if (msgid == -1)
    {
        fprintf(stderr, "Create message failed!");
        exit(EXIT_FAILURE);
    }
    while (running)
    {
        // them ban tin vao hang doi
        printf("Enter some text:");
        fgets(buffer, MAX_SIZE, stdin);
        mystruct.type = 1;
        strcpy(mystruct.text, buffer);
        if (msgsnd(msgid, (void *)&mystruct, MAX_SIZE, 0) == -1)
        {
            fprintf(stderr, "Error !");
            exit(EXIT_FAILURE);
        }
        if (strncmp(buffer, "end", 3) == 0)
        {
            printf("Bye !\n");
            running = 0;
        }
    }
    exit(EXIT_SUCCESS);
}
