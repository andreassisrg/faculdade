#include <stdio.h>
#include <stdlib.h>

int soma(int vetor[], int tamanho_vetor);

int main(void)
{
    // Recebe dados do prompt: vetor e tamanho
    int n;
    scanf("%d", &n);
    int vetor[n];
    for (int i = 0; i < n; i++)
    {
        scanf("\n");
        scanf("%d", &vetor[i]);
    }
    
    // Chama a função e imprime seu resultado
    int res = soma(vetor, n);
    printf("%d\n", res);
}

int soma(int vetor[], int tamanho_vetor)
{
    if (tamanho_vetor - 1 == 0)
    {
        return vetor[tamanho_vetor - 1];
    }
    else
    {
        return vetor[tamanho_vetor - 1] + soma(vetor, tamanho_vetor - 1);
    }
}