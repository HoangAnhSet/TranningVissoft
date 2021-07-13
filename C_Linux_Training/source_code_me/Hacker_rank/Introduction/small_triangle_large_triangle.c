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
void swap(triangle *tr1, triangle *tr2)
{
    struct triangle tmp;
    tmp.a = tr1->a;
    tmp.b = tr1->b;
    tmp.c = tr1->c;
    tr1->a = tr2->a;
    tr1->b = tr2->b;
    tr1->c = tr2->c;
    tr2->a = tmp.a;
    tr2->b = tmp.b;
    tr2->c = tmp.c;
}
double area(triangle tr)
{
    float p ;
    p= (tr.a + tr.b + tr.c) / 2;
    double S ;
    S= sqrt(p * (p - tr.a)* (p - tr.b) * (p - tr.c));
    return S;
}
void sort_by_area(triangle *tr, int n)
{   
   
    for (int i = 0; i < n; i++)
    {
        double minArea = area(tr[i]);
        int indexMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (minArea > area(tr[j]))
            {
                minArea=area(tr[j]);
                indexMin = j;
            }
        }
        swap(&tr[i], &tr[indexMin]);
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
3
7 24 25
5 12 13
3 4 5

*/