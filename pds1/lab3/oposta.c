#include <stdio.h>

int main(void)
{
    // Número de linhas e colunas
    int n_lin, n_col;
    scanf("%i %i", &n_lin, &n_col);
    
    // Criando a matriz
    int matriz[n_lin][n_col];
    for (int i = 0; i < n_lin; i++)
    {
        for (int j = 0; j < n_col; j++)
        {
            scanf("%i", &matriz[i][j]);
        }
    }
    
    // Imprimindo a oposta
    for (int i = 0; i < n_lin; i++)
    {
        for (int j = 0; j < n_col; j++)
        {
            printf("%d ", (-1) * matriz[i][j]);
        }
        printf("\n");
    }
}