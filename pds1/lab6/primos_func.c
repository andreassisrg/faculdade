#include <stdio.h>

int is_prime(long long int number);

int main(void)
{
    long long int n;
    while(scanf("%lld", &n) != EOF)
    {
        printf("%d\n", is_prime(n));
    }
    
    return 0;
}

int is_prime(long long int number)
{
    if (number < 2)
        return -1;
        
    int factors = 0;
    for (long long int i = 1; i < number + 1; i++)
    {
        if (number % i == 0)
        {
            factors++;
        }
    }
    
    if (factors == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}