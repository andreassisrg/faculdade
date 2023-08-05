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
    
    // Coletando maior número da matriz
    int maior = matriz[0][0];
    for (int i = 0; i < n_lin; i++)
    {
        for (int j = 0; j < n_col; j++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
            }
        }
    }
    printf("%i\n", maior);
    
    return 0;
}