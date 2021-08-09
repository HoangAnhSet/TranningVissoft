// prinft function
/* #include<stdio.h>
int main()
{ // hiện thị
    // 10.3f => dùng 10 kí tự để thể hiện trong đó có 3 kí tự sau số thập phân
    // 
    int x,y;
    float a,b,c;
    double h;
    x=1;
    y=4;
    a=43.123;
    b=43.0000;

    printf("%f, %d, %f, %f",x,y,a,b);
} */
// scanf function
// => scanf sẽ dựng lại khi gặp dấu enter "Kết luận là không phải".
// nó sẽ điền đủ giá trị thì thôi
/* #include<stdio.h>
int main()
{
    int x,y,z,k;
    int a,b,c,d;
    scanf("%d %d %d %d", &x, &y,&z, &k);
    scanf("%d %d %d %d", &a, &b,&c, &d);
    printf("%d, %d, %d, %d\n",x,y,z,k);
    printf("%d, %d, %d, %d",a,b,c,d);
} */
///////////////////////////////// Some Q&A ////////////////
// câu 1 sự khác nhau của %i và %d
//Trả lời: Nếu trong hàm printf thì hai kí tự này không khác nhau, 
/* // nhưng trong scanf thì khác nhau. %i sẽ phân biệt được giá trị octal, hexial so với %d.

#include<stdio.h>
int main()

{
    int x,y,z;
    scanf("%d",&x);
    scanf("%i",&y);
    printf("%d\n",x);
    printf("%d\n",y);
} */

/* // Câu 2 làm thế nào in được kí tự % => viết hai lần % như trong ví dụ dưới
#include<stdio.h>
int main()
{
    int x=5;
    printf("%d %%",x);
} */

// Câu 3 hiện tượng nào khi người dùng input không phải vào số vào hàm scanf

#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    printf("%d",x);

}