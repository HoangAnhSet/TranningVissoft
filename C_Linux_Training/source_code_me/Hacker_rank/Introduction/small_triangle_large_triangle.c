#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;
// void swap(triangle *tr1, triangle *tr2)
// {
//     struct triangle tmp;
//     tmp.a = tr1->a;
//     tmp.b = tr1->b;
//     tmp.c = tr1->c;
//     tr1->a = tr2->a;
//     tr1->b = tr2->b;
//     tr1->c = tr2->c;
//     tr2->a = tmp.a;
//     tr2->b = tmp.b;
//     tr2->c = tmp.c;
// }
// double area(triangle tr)
// {
//     // float p ;
//     // p= (tr->a + tr->b + tr->c) / 2;
//     // double S ;
//     // S= sqrt(p * (p - tr->a)* (p - tr->b) * (p - tr->c));

//     // return S;
//     int a=tr.a;
//     int b=tr.b;
//     int c=tr.c;
//     return (a+b+c)*(a-b+c)*(a+b-c)*(-a+b+c);

// }
// void sort_by_area(triangle *tr, int n)
// {   
   
//     // for (int i = 0; i < n; i++)
//     // {
//     //     // double minArea = area(tr[i]);
//     //     // int indexMin = i;
//     //     // for (int j = i + 1; j < n; j++)
//     //     // {
//     //     //     if (minArea > area(tr[j]))
//     //     //     {
//     //     //         minArea=area(tr[j]);
//     //     //         indexMin = j;
//     //     //     }
//     //     // }
//     //     // swap(&tr[i], &tr[indexMin]);
        
//     // }
//     int i, j, min_idx;
    
//     // One by one move boundary of unsorted subarray
//     for (i = 0; i < n-1; i++)
//     {
//         // Find the minimum element in unsorted array
//         min_idx = i;
//         for (j = i+1; j < n; j++)
//           if (arr[j] < arr[min_idx])
//             min_idx = j;
 
//         // Swap the found minimum element with the first element

//         swap(&arr[min_idx], &arr[i]);
//     }
// }

// void sort_by_area(triangle *tr, int n)
// {
//     int i, j, min_idx;
 
//     // One by one move boundary of unsorted subarray
//     for (i = 0; i < n-1; i++)
//     {
//         // Find the minimum element in unsorted array
//         min_idx = i;
//         for (j = i+1; j < n; j++)
//           if (area(tr[j]) < area(tr[min_idx]))
//             min_idx = j;
 
//         // Swap the found minimum element with the first element
//         swap(&tr[min_idx],& tr[i]);
//     }
// }
void swap(triangle* a,triangle* b)
{
    triangle temp=*a;
    *a=*b;
    *b=temp;
}
int cmp(triangle tr)
{
    int a=tr.a;
    int b=tr.b;
    int c=tr.c;
    return (a+b+c)*(a-b+c)*(a+b-c)*(-a+b+c);
}
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    for(int i=0;i<n;i++)
    {
        int swapped=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(cmp(tr[j])>cmp(tr[j+1]))
             swap(&tr[j],&tr[j+1]);
            swapped=1;
        }
        if(swapped==0)
            break;
    }
   
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}
/* test case
20
23 37 47
22 18 5
58 31 31
28 36 40
54 62 11
31 41 14
53 18 54
41 38 55
55 44 44
44 48 18
26 41 65
20 23 21
58 61 50
28 56 56
20 39 32
33 45 49
26 41 62
31 46 39
48 49 67

*/