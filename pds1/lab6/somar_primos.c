#include <ctype.h>
#include <stdio.h>
#include <math.h>

int is_prime(long long int number);
unsigned long long int sum_primes(long long int n);

int main(void)
{
    long long int n;
    while(scanf("%lld", &n) != EOF)
    {
        printf("%llu\n", sum_primes(n));
    }
}

int is_prime(long long int number)
{
    if (number < 2)
        return -1;
    
    if (number != 2 && number % 2 == 0)
        return 0;
        
    if (number != 5 && number % 5 == 0)
        return 0;
    
    int factors = 0;
    for (long long int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

unsigned long long int sum_primes(long long int n)
{
    unsigned long long int sum = 0;
    long long int i = 2;
    unsigned int count = 0;
    
    while (count < n)
    {
        if (i == 2)
        {
            sum += i;
            i++;
            count++;
            if (count >= n)
            {
                return sum;
            }
        }
        if (is_prime(i) == 1)
        {
            sum += i;
            count++;
        }
        i+=2;
    }
    
    return sum;
}