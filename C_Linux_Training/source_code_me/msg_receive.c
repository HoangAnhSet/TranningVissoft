#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/msg.h>
#include<string.h>

struct data
{
    long int type;
    char text[BUFSIZ];
};
int main()
{
    int runing=1;
    int msgid;
    struct data mydata;
    msgid=msgget((key_t)1234,0666|IPC_CREAT);
    if(msgid==-1)
    {
        printf("Initi failed !");
        exit(EXIT_FAILURE);
    }
    //Nhan du lieu tu hang doi
    while(runing)
    {
        
        if(msgrcv(msgid, (void *) &mydata,BUFSIZ,0,0)==-1)
        {
            printf("MSGRCV error!\n");
            exit(EXIT_FAILURE);
        }
        printf("Your text:%s",mydata.text);
    }
    exit(EXIT_SUCCESS);
}
// #include<stdlib.h>
// #include<stdio.h>
// #include<string.h>
// #include<errno.h>


// #include<unistd.h>


// #include<sys/msg.h>

// struct data
// {
//     long int my_msg_type;
//     char some_text[BUFSIZ];// bufsiz=8192
// };
// int main()
// {
//     int running =1;
//     int msgid;
//     struct data myData;
//     long int msg_to_receive=0;
//     // set up the message queue
//     msgid=msgget((key_t)1234, 0666|IPC_CREAT);

//     if(msgid==-1)
//     {
//         fprintf(stderr,"Msgget failed with error: %d\n", errno);
//         exit(EXIT_FAILURE);
//     }

//     //tin nhawns se duoc lay lai truc khi co mot tin nhan duoc gui
//     //den hang doi
//     while(running)
//     {
//         if(msgrcv(msgid, (void *) &myData,BUFSIZ,msg_to_receive,0)==-1)
//         {
//             fprintf(stderr, "msgrcv failed with error: %d\n",errno);
//             exit(EXIT_FAILURE);
//         }
//         printf("You wrote:%s", myData.some_text);
//         if(strncmp(myData.some_text, "end",3)==0)
//         {
//             running =0;
//         }
//     }
//     // if (msgctl(msgid, IPC_RMID, 0)==-1)
//     // {
//     //     fprintf(stderr,"msgctl(IPC_RMID failed\n");
//     //     exit(EXIT_FAILURE);
//     // }
//     exit(EXIT_SUCCESS);
// }