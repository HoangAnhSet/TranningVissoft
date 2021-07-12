#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int sockfd;
    int len;
    struct sockaddr_un address;
    int result;
    char ch = 'A';
    //Create a socket for the client
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    //Name the socket as agreed with the server
    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, "server_socket");
    len = sizeof(address);
    //Connect your socket to the server socket;
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if (result == -1)
    {
        perror("opps:client1");
        exit(1);
    }
    //You cand now read and write via sockfd
    write(sockfd, &ch, 1);
    read(sockfd, &ch, 1);
    printf("char from server=%c\n", ch);
    close(sockfd);
    exit(0);
}
//result opps:client1: No such file or directory