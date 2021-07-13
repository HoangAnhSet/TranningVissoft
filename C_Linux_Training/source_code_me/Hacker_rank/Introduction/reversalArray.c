#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = malloc(num * sizeof(int));
    for (i = 0; i < num; i++)
    {
        scanf("%d", arr + i);
    }

    for(int i=0;i<num/2;i++)
    {
        swap(arr+i,arr+num-i-1);
    }
    for (i = 0; i < num; i++)
        printf("%d ", *(arr + i));

    return 0;
}
// test case
/*
8
15 5 16 15 17 11 5 11 
*/