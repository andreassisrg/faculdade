#include <stdio.h>
#include <stdlib.h>

void imprime(int vetor[], int n);
void multiplica(int vetor[], int n, double v);

int main(void)
{
    // Tamanho do vetor
    int n;
    scanf("%d", &n);
    
    // Pega o vetor do prompt
    int vetor[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &vetor[i]);
    }
    
    // Pede ao usuário pelo fator multiplicativo
    double fator;
    scanf("%lf", &fator);
    
    // Imprimindo vetor inicial
    imprime(vetor, n);
    
    // Multiplica o vetor inicial pelo fator multiplicativo e imprime
    multiplica(vetor, n, fator);
    imprime(vetor, n);
    
    // Multiplica o vetor inicial pelo inverso do fator multiplicativo e imprime
    multiplica(vetor, n, 1/fator);
    imprime(vetor, n);
    
    return EXIT_SUCCESS;
}

void imprime(int vetor[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", vetor[i]);
    }
}

void multiplica(int vetor[], int n, double v)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] = vetor[i] * v;
    }
}