// hàm fork() dùng để tạo ra các tiến trình hoặc các luồng trên một mã nhưng khác nhau ở không gian bộ nhớ, dữ liệu
// sử dụng hai thư viện
#include<sys/types.h>  // chứa hàm fork()
#include<unistd.h>
#include<stdio.h> // chứa các hàm input, output.
#include<stdlib.h>

int main()
{
    pid_t pid;
    char *message;
    int n;
    printf("fork program starting\n");
    pid =fork();
    switch(pid)
    {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message="This is the child";
            n=5;
            break;
        default:
            message="This is the parrent";
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
