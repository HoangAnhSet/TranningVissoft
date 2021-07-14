#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char date[33] = "";
    char *ptr = "May 24";

    
    scanf("%[^\n]s",date);
    printf("%s",date);
    

    return 0;
}