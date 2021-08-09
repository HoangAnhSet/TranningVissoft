// mutiDemension
#include<stdio.h>

int main()
{    // Khai báo 
    //int arr[3][4]={{1,2,3,4},{4,5,6,7},{7,8,9,10}}; // mảng có tên là arr, kiểu số nguyên, có 5 hàng và 9 cột
    // Khai báo kiểu các phần tử liên tiếp

    //int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};

    // int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12,13}; // Khai báo thừa phần tử sẽ gặp lỗi warning: excess elements in array initializer
    // Cách lưu trữ giống như lưu nhiều mảng một chiều, từng hàn được coi là một mảng một chiều
    // => vì thế mà các khai báo giống như mảng của mảng một chiều
    // Khai báo thiếu phần tử trong một hàng => phần tử thiếu sẽ được điền giá trị là 0
    //int arr[3][4]={{1,2,3},{4,5,6},{7,8,9}};
    int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12,13}; // Khai báo thử
    for(int i=0;i<3;i++)
        {
            for(int j=0;j<4;j++)
            {
                printf("%d",arr[i][j]);
            }
            printf("\n");
        }
}
// Dùng con trỏ cho mảng hai chiều