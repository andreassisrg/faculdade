#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void media(double vet[], int n, int *i);

int main(void)
{
    int n, perto;
    scanf("%d", &n);
    double vetor[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &vetor[i]);
    }
    
    media(vetor, n, &perto);
    
    return EXIT_SUCCESS;
}

void media(double vet[], int n, int *i)
{
    double media = 0;
    for (int j = 0; j < n; j++)
    {
        media += vet[j];
    }
    media /= n;
    
    *i = 0;
    for (int k = 1; k < n; k++)
    {
        if (abs(vet[k] - media) < abs(vet[*i] - media))
        {
            *i = k;
        }
    }
    
    printf("%d\n", *i);
}