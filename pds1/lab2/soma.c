#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i", &n);

    int res = 0;
    for (int i = 0; i <= n; i++)
    {
        res += i;
    }
    
    printf("%i\n", res);
}