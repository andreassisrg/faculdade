// Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do produto
typedef struct
{
    char codigo[30];
    char nome[256];
    unsigned int quantidade;
    float preco;
    char estado[5];
}
produto;

// Declaração de funções
void relatorio_estoque(produto produtos[], char *out, int n_itens);
void produto_pelo_codigo(produto produtos[], char *codigo, int n_itens);
void menor_quantidade(produto produtos[], int n_itens);
void produto_pelo_estado(produto produtos[], char *estado, int n_itens);
void produto_menor_estado(produto produtos[], char *estado, int n_itens);
void total(produto produtos[], int n_itens);

int main(int argc, char *argv[])
{
    // Abrindo arquivo
    FILE *fptr = fopen(argv[1], "r");
    if (fptr == NULL)
        exit(1);

    // Descobrindo a quantia de itens
    int n_itens;
    fscanf(fptr, "%d", &n_itens);

    // Lendo produtos para o vetor "produtos"
    produto produtos[n_itens];
    for (int i = 0; i < n_itens; i++)
    {
        fscanf(fptr, "\n");
        fgets(produtos[i].codigo, 30, fptr);
        produtos[i].codigo[strlen(produtos[i].codigo) - 1] = '\0';
        fscanf(fptr, "\n");
        fgets(produtos[i].nome, 256, fptr);
        produtos[i].nome[strlen(produtos[i].nome) - 1] = '\0';
        fscanf(fptr, "\n");
        fscanf(fptr, "%u\n", &produtos[i].quantidade);
        fscanf(fptr, "%f\n", &produtos[i].preco);
        fgets(produtos[i].estado, 5, fptr);
        // A condicional é necessária para lidar com a última entrada, pois pode não haver '\n'
        if (produtos[i].estado[strlen(produtos[i].estado) - 1] == '\n')
            {
                produtos[i].estado[strlen(produtos[i].estado) - 1] = '\0';
            }
        else
        {
            produtos[i].estado[strlen(produtos[i].estado)] = '\0';
        }
    }
    fclose(fptr);

    // Chamada de função determinada pela linha de comando
    switch(atoi(argv[2]))
    {
        case 1:
            relatorio_estoque(produtos, argv[3], n_itens);
            break;
        case 2:
            produto_pelo_codigo(produtos, argv[3], n_itens);
            break;
        case 3:
            menor_quantidade(produtos, n_itens);
            break;
        case 4:
            produto_pelo_estado(produtos, argv[3], n_itens);
            break;
        case 5:
            produto_menor_estado(produtos, argv[3], n_itens);
            break;
        case 6:
            total(produtos, n_itens);
            break;
    }
    
    return EXIT_SUCCESS;
}

void relatorio_estoque(produto produtos[], char *out, int n_itens)
{
    /* O programa deve gerar um arquivo TXT, com o nome passado pelo param3, salvo no mesmo
    diretório de execução. Deve-se salvar a lista de todos os produtos COM OS NOMES EM ORDEM
    ALFABÉTICA, com os mesmos dados da entrada, um dado por linha (Código, Nome, Quantidade, Preço e Estado).*/

    // Colocando em ordem alfabetica
    produto tmp;
    for (int i = 0; i < n_itens; i++)
    {
        for (int j = 0; j < n_itens; j++)
        {
            if (strcmp(produtos[i].nome, produtos[j].nome) < 0)
            {
                tmp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = tmp;
            }
        }
    }

    // Criando o arquivo de output
    FILE *outptr = fopen(out, "w");
    if (outptr == NULL)
        exit(1);

    // Escrevendo o arquivo de output
    for (int i = 0; i < n_itens; i++)
    {
        fprintf(outptr, "%s\n", produtos[i].codigo);
        fprintf(outptr, "%s\n", produtos[i].nome);
        fprintf(outptr, "%u\n", produtos[i].quantidade);
        fprintf(outptr, "%.2f\n", produtos[i].preco);
        fprintf(outptr, "%s\n", produtos[i].estado);
    }
}

void produto_pelo_codigo(produto produtos[], char *codigo, int n_itens)
{
    /* O programa deverá imprimir na saída padrão (tela) todos os dados do produto que tenha o
    código igual ao informado no param3, um dado por linha (Código, Nome, Quantidade, Preço e Estado). */

    // Percorrendo os produtos até achar o código pedido
    for (int i = 0; i < n_itens; i++)
    {
        if (strcmp(produtos[i].codigo, codigo) == 0)
        {
            printf("%s\n", produtos[i].codigo);
            printf("%s\n", produtos[i].nome);
            printf("%u\n", produtos[i].quantidade);
            printf("%.2f\n", produtos[i].preco);
            printf("%s\n", produtos[i].estado);
            return;
        }
    }
}

void menor_quantidade(produto produtos[], int n_itens)
{
    /*O programa deverá imprimir na saída padrão (tela) todos os dados do produto que possui
    a menor quantidade em estoque, um dado por linha (Código, Nome, Quantidade, Preço e Estado).*/

    // Percorrendo pelo produto com menor quantidade
    produto menor = produtos[0];
    for (int i = 1; i < n_itens; i++)
    {
        if (produtos[i].quantidade < menor.quantidade)
        {
            menor = produtos[i];
        }
    }
    printf("%s\n", menor.codigo);
    printf("%s\n", menor.nome);
    printf("%u\n", menor.quantidade);
    printf("%.2f\n", menor.preco);
    printf("%s\n", menor.estado);
}

void produto_pelo_estado(produto produtos[], char *estado, int n_itens) // Falta a ordem alfabética
{
    /*O programa deverá imprimir na saída padrão (tela) a lista de produtos do estado informado no param3,
    EM ORDEM ALFABÉTICA, com todos os dados de cada produto, um dado por linha (Código, Nome, Quantidade, Preço e Estado).*/

    // Colocando em ordem alfabética
    produto tmp;
    for (int i = 0; i < n_itens; i++)
    {
        for (int j = 0; j < n_itens; j++)
        {
            if (strcmp(produtos[i].nome, produtos[j].nome) < 0)
            {
                tmp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = tmp;
            }
        }
    }

    // Percorrendo pelo estado determinado e imprimindo na tela
    for (int i = 0; i < n_itens; i++)
    {
        if (strcmp(produtos[i].estado, estado) == 0)
        {
            printf("%s\n", produtos[i].codigo);
            printf("%s\n", produtos[i].nome);
            printf("%u\n", produtos[i].quantidade);
            printf("%.2f\n", produtos[i].preco);
            printf("%s\n", produtos[i].estado);
        }
    }
}

void produto_menor_estado(produto produtos[], char *estado, int n_itens)
{
    /*O programa deverá imprimir na saída padrão (tela) o produto do estado informado no param3 que possui
    a menor quantidade em estoque, um dado por linha (Código, Nome, Quantidade, Preço e Estado).*/

    // Cria uma variável temporária com o estado específico
    produto menor;
    for (int i = 0; i < n_itens - 1; i++)
    {
        if (strcmp(estado, produtos[i].estado) == 0)
        {
            menor = produtos[i];
            break;
        }
    }
    // Compara a variável temporária contra todos os outros produtos que possuem os mesmos critérios (estado e quantia)
    for (int i = 0; i < n_itens; i++)
    {
        if (strcmp(estado, produtos[i].estado) == 0 && produtos[i].quantidade < menor.quantidade)
            menor = produtos[i];
    }

    // Imprime a variável temporária na tela
    printf("%s\n", menor.codigo);
    printf("%s\n", menor.nome);
    printf("%u\n", menor.quantidade);
    printf("%.2f\n", menor.preco);
    printf("%s\n", menor.estado);
}

void total(produto produtos[], int n_itens)
{
    /*O programa deverá imprimir na saída padrão (tela) a quantidade total de itens e, em seguida,
    o preço total (R$) de todos os produtos presentes no estoque. Para o cálculo da quantidade total
    de itens do estoque deve-se somar a quantidade de cada produto, recebida no arquivo de entrada. */

    unsigned int qntd_total = 0;
    for (int i = 0; i < n_itens; i++)
    {
        qntd_total += produtos[i].quantidade;
    }
    printf("%u\n", qntd_total);
}