#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char *s;
    char *ch;
    char *sen;

    s = malloc(1024 * sizeof(char));
    ch = malloc(1024 * sizeof(char));
    sen= malloc(1024 * sizeof(char));
    
        scanf("%[^\n]%*c", s);
        scanf("%[^\n]%*c", ch);
        scanf("%[^\n]%*c", sen);
        printf("%s\n", s);
        printf("%s\n", ch);
        printf("%s\n", sen);
    
    return 0;
}
