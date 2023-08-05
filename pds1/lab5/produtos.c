#include <stdio.h>
#include <string.h>

#define DEBUG 0

typedef struct
{
    char nome[50];
    char marca[50];
    float preco;
}
produto;

int main(void)
{
    produto produtos[8];
    for (int i = 0; i < 8; i++)
    {
        scanf("%s %s %f", produtos[i].nome, produtos[i].marca, &produtos[i].preco);
        if (DEBUG) { printf("%.2f\n", produtos[i].preco); }

    }
    
    char marcas[8][50];
    int existe = 0;
    int cont = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (strcmp(produtos[i].marca, marcas[j]) == 0)
            {
                existe = 1;
            }
        }
        if (!existe)
        {
            strcpy(marcas[cont], produtos[i].marca);
            cont++;
        }
        else
        {
            existe = 0;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < cont; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (strcmp(marcas[i], produtos[j].marca) == 0)
            {
                ans++;
            }
        }
        printf("%s %i\n", marcas[i], ans);
        ans = 0;
    }
    
    float media_total = 0;
    for (int i = 0; i < 8; i++)
    {
        media_total += produtos[i].preco;
    }
    printf("media total %.2f\n", media_total / 8.0);
    
    float media_parcial = 0;
    float div = 0.0;
    for (int i = 0; i < cont; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (strcmp(marcas[i], produtos[j].marca) == 0)
            {
                media_parcial += produtos[j].preco;
                div += 1.0;
            }
        }
        printf("media %s %.2f\n", marcas[i], media_parcial/div);
        media_parcial = 0;
        div = 0.0;
    }
    return 0;
}