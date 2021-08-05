#include<stdio.h>
// Con trỏ và mảng
int main()
{
    // Con trỏ dùng để truy xuất tới các thành viên trong mảng
    // Khai bao một mảng
    short int arr1[3]={1,2,3}; //Kiểu short int có kich thước là 2 byte có giá trị là-32768->32767
    long int arr2[3]={3,4,5};//kiểu long int có kích thước là 4 byte có giá trị là -2.147.483.648->2.147.483.647 khoảng 2 tỷ 100 trăm 47 triệu
    //Khai bao con tro
    short int *ptr;
    // Gán giá trị của con trỏ tới đỉa chỉ của mảng
    ptr=arr1;
    //Truy xuất tới từng thành viên trong mảng dùng cú pháp ptr+i, i= giá trị index của thành viên
    printf("%d",*(ptr+1));

    

}
// long int a;
//     short int b;

//     printf("%d",sizeof(a));
//     printf("%d",sizeof(b));