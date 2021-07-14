#include<stdio.h>
#include<string.h>
int main()
{
    int a[]={99,1,[0]=2,3,[9]=9};
    int b[3];
    memccpy(b,a,sizeof(b));
    for(int i=0;i<10;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}