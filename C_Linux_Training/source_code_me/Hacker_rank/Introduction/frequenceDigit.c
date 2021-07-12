#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    int arry[10] = {0};
    for (int i = 0; i < strlen(s); i++)
    {
        switch (*(s + i))
        {
        case '1':
            arry[0]++;
            break;
        case '2':
            arry[1]++;
            break;
        case '3':
            arry[2]++;
            break;
        case '4':
            arry[3]++;
            break;
        case '5':
            arry[4]++;
            break;
        case '6':
            arry[5]++;
            break;
        case '7':
            arry[6]++;
            break;
        case '8':
            arry[7]++;
            break;
        case '9':
            arry[8]++;
            break;
            case '0':
            arry[9]++;
            break;
        default:
            break;
        }
    }
    printf("%d ",arry[9]);
    for (int i = 0; i < 9; i++)
    {
         printf("%d ",arry[i]);
    }
    return 0;
}
