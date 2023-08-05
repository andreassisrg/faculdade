#include <stdio.h>

int main(void)
{
    int n = 0;

    while (1)
    {
        scanf("%d", &n);
        
        // If the number is negative or greatar than 800, exit
        if (n < 0 || n > 800)
        {
            return 0;
        }
        
        // Create the fibonacci sequence until the 'n' position
        int fib[n];
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            fib[i] = fib[i-1] + fib[i-2];
        }
        printf("%d\n", fib[n]);
    }
}