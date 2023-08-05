#include <stdio.h>
#define LEN 10

int main(void)
{
    int X[LEN];
    for (int i = 0; i < LEN; i++)
    {
        scanf("%d\n", &X[i]);
    }

    for (int i = LEN-1; i >= 0; i--)
    {
        printf("%d\n", X[i]);
    }
    
    return 0;
}