#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct triangle
{
    int a;
    int b;
    int c;

};
typedef struct triangle triangle;
double area(triangle tr)
{
    float p ;
    p= (tr.a + tr.b + tr.c) / 2;
    double s ,S;
    s=p * (p - tr.a)* (p - tr.b) * (p - tr.c);
    S=sqrt(s);
    return S;
}
int main()
{
    triangle tr1;
    tr1.a=3;
    tr1.b=4;
    tr1.c=5;
    printf("%f",area(tr1));

    

}
// test case
/*
3 4 5
5 12 13
7 24 25
*/
