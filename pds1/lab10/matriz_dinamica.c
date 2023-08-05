#include <stdio.h>
#include <stdlib.h>

int **inicializa_mat(int l, int c);
void imprime_mat(int **mat, int l, int c);
void libera_mat(int **m);

int main(void)
{
    // Numero de linhas e colunas da matriz
    int l, c;
    scanf("%d\n", &l);
    scanf("%d", &c);
    
    // Inicializa, imprime e libera matriz
    int **matriz = inicializa_mat(l, c);
    imprime_mat(matriz, l, c);
    libera_mat(matriz);
}

int **inicializa_mat(int l, int c)
{
    // Cria matriz por meio de alocação dinâmica
    // Matriz é linear na memória, com indíces 2D (ponteiro duplo, colunas ponteiro simples)
    int **mat;
    mat = (int **) malloc(l * sizeof(int *));
    mat[0] = (int *) malloc(l * c * sizeof(int));
    
    for (int i = 1; i < l; i++)
    {
        mat[i] = c*i + mat[0];
    }
    
    // Preenche a matriz com dados do prompt
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("\n");
            scanf("%d", &mat[i][j]);
        }
    }
    
    return mat;
}

void imprime_mat(int **mat, int l, int c)
{
    // Imprime matriz
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void libera_mat(int **mat)
{
    // Libera memória do vetor, e depois o ponteiro duplo
    free(mat[0]);
    free(mat);
}