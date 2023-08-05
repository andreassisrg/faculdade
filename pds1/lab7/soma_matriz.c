#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //Pega nome do arquivo
    char nome_arq[20];
    fgets(nome_arq, 20, stdin);
    nome_arq[strlen(nome_arq) - 1] = '\0';
    
    //Abre arquivo
    FILE *fptr = fopen(nome_arq, "rb");
    if (fptr == NULL)
        exit(1);
    
    //Lê duas matrizes
    unsigned int matriz1[5][5], matriz2[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fscanf(fptr, "%u", &matriz1[i][j]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fscanf(fptr, "%u", &matriz2[i][j]);
        }
    }
    
    //Imprime resultado
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%u ", matriz1[i][j] + matriz2[i][j]);
        }
        printf("\n");
    }
    
    fclose(fptr);
    return 0;
}