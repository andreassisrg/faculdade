#include <stdio.h>
#include <stdlib.h>

void le_vetor(int *ptr, int n);
void imprime_vetor(int *ptr, int n);

int main(void)
{
    // Número de elementos do vetor
    int n;
    scanf("%d", &n);
    
    // Vetor dinâmico de tamanho n
    int *vetor;
    vetor = (int *) malloc(n * sizeof(int));
    
    // Lê o prompt e imprime
    le_vetor(vetor, n);
    imprime_vetor(vetor, n);
    
    free(vetor);
}

void le_vetor(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("\n");
        scanf("%d", ptr + i);
    }
}

void imprime_vetor(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", *(ptr + i));
    }
}