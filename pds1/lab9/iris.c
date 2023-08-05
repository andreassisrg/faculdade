#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double comprimento_sepala;
    double largura_sepala;
    double comprimento_petala;
    double largura_petala;
    char tipo[50];
}
iris;

void classificar(iris nao_identificada, iris registros_identificados[], int n);

int main(void)
{
    // Pega o número de registros
    int n;
    scanf("%d\n", &n);
    
    // Pega todas as n iris do prompt
    iris registros[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf %lf %lf ", &registros[i].comprimento_sepala,
        &registros[i].largura_sepala, &registros[i].comprimento_petala, &registros[i].largura_petala);
        fgets(registros[i].tipo, 50, stdin);
        registros[i].tipo[strlen(registros[i].tipo) - 1] = '\0';
    }
    
    // Recebe a iris que deseja comparar
    iris desconhecida;
    scanf("%lf %lf %lf %lf", &desconhecida.comprimento_sepala,
    &desconhecida.largura_sepala, &desconhecida.comprimento_petala, &desconhecida.largura_petala);
    
    // Compara a iris desconhecida com o vetor de n iris e imprime na tela
    classificar(desconhecida, registros, n);
    
    return EXIT_SUCCESS;
}

void classificar(iris nao_identificada, iris registros_identificados[], int n)
{
    /* Função que usa a distância euclidiana para classificar uma flor desconhecida
    a um vetor que contenha informação prévia de outras flores */
    
    double distancia;
    double menor;
    int index;
    for (int i = 0; i < n; i++)
    {
        distancia = 
        pow(nao_identificada.comprimento_sepala - registros_identificados[i].comprimento_sepala, 2) +
        pow(nao_identificada.largura_sepala - registros_identificados[i].largura_sepala, 2) +
        pow(nao_identificada.comprimento_petala - registros_identificados[i].comprimento_petala, 2) +
        pow(nao_identificada.largura_petala - registros_identificados[i].largura_petala, 2);
        
        if (i == 0 || distancia < menor)
        {
            menor = distancia;
            index = i;
        }
    }
    
    // Imprime a flor com menor distância, armazenada na variável "index"
    printf("%s\n", registros_identificados[index].tipo);
}