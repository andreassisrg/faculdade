#include <stdio.h>
#include <stdlib.h>

int *soma_vetores(int *v1, int *v2, int n);

int main(void)
{
    // Tamanho dos dois vetores
    int n;
    scanf("%d", &n);
    
    // Inicializa vetores iniciais
    int *v1, *v2;
    v1 = (int *) malloc(n * sizeof(int));
    v2 = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("\n");
        scanf("%d", &v1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("\n");
        scanf("%d", &v2[i]);
    }
    
    // Soma vetores e imprime o vetor resultante
    int *v3 = soma_vetores(v1, v2, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", v3[i]);
    }
    
    // Libera toda a memória usada
    free(v1);
    free(v2);
    free(v3);
}

int *soma_vetores(int *v1, int *v2, int n)
{
    // Cria vetor que armazenará o resultado
    int *v3 = (int *) malloc(n * sizeof(int));
    
    // Percorre vetores e realiza a soma
    for (int i = 0; i < n; i++)
    {
        v3[i] = v1[i] + v2[i];
    }
    
    return v3;
}