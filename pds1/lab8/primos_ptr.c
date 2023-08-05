#include <math.h>
#include <stdio.h>

int eh_primo(int num);
void primos(int m, int *p1, int *p2);

int main(void)
{
    int m, p1, p2;
    scanf("%d", &m);
    primos(m, &p1, &p2);
}

int eh_primo(int num)
{
    if (num == 2)
        return 1;
    
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return 0;
    }
    
    return 1;
}

void primos(int m, int *p1, int *p2)
{
    *p1 = m;
    *p2 = m;
    
    while (1)
    {
        (*p1)--;
        if (eh_primo(*p1) == 1)
        {
            printf("%d\n", *p1);
            break;
        }
    }
    
    while (1)
    {
        (*p2)++;
        if (eh_primo(*p2) == 1)
        {
            printf("%d\n", *p2);
            break;
        }
    }
}