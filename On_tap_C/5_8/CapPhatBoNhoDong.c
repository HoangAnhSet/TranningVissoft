#include<stdio.h>
#include<stdlib.h>

int main()
{
 /*   //kiem tra kich thuoc cua con tro so nguyen va so nguyen
    int *ptr;
    int n;   
    printf("kich thuoc cua con tro=%d\n",sizeof(ptr));
    printf("kich thuoc cua so nguyen=%d\n",sizeof(n));
    => Kich thuoc giá trị và con trỏ là giống nhau.
 */
/* Khai Báo không gian bộ nhớ sử dụng malloc trong thư viện stdlib
   //malloc
   int *ptr;
   ptr=(int *)malloc(100*sizeof(int));
*/
/*  // Cấp Phát bộ nhớ sử dụng calloc(), giá trị khởi tạo sẽ bằng 0.
    int *ptr;
   ptr=(int *)calloc(100,sizeof(int));
*/
/* // Giải phóng không gian bộ nhớ trong C/C++
int *ptr;
int *ptr2;
// Khai báo
ptr=(int *)malloc(100*sizeof(int));
ptr2=(int *)calloc(100,sizeof(int));
//Giải phóng bộ nhớ
free(ptr);
free(ptr2); */

}