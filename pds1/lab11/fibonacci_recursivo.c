#include <stdio.h>

int fibonacci(int n);

int main(void)
{
    // Recebe do usuário qual número da sequência deve ser calculado
    int n;
    scanf("%d", &n);
    
    // Chama função recursiva
    int res = fibonacci(n);
    printf("%d\n", res);
}

int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}