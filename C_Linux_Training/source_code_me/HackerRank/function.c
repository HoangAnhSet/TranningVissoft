#include <stdio.h>
int max_of_four(int a,int b,int c,int d)
{
    int smp1;
    int smp2;
    smp1=a>b?a:b;
    smp2=c>d?c:d;
    return smp1>smp2?smp1:smp2;
}
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d",ans);
    // printf("%d %d %d %d",a,b,c,d);
    
    
    return 0;
}