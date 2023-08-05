#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
    char telefone[20];
}
contato;

void inserir(char *arquivo);
void alterar(char *arquivo);
void excluir(char *arquivo);
void exibir(char *arquivo);

int main(void)
{
    char nome_arq[50];
    fgets(nome_arq, 50, stdin);
    nome_arq[strlen(nome_arq) - 1] = '\0';
    
    char buffer[256];
    while(scanf("%s", buffer) != EOF)
    {
        if (strcmp(buffer, "Inserir") == 0)
        {
            inserir(nome_arq);
        }
        else if (strcmp(buffer, "Alterar") == 0)
        {
            alterar(nome_arq);
        }
        else if (strcmp(buffer, "Excluir") == 0)
        {
            excluir(nome_arq);
        }
        else if (strcmp(buffer, "Exibir") == 0)
        {
            exibir(nome_arq);
        }
        else
        {
            continue;
        }
    }
    
    return EXIT_SUCCESS;
}

void inserir(char *arquivo)
{
    scanf("\n");
    
    FILE *fptr = fopen(arquivo, "a+b");
    if (fptr == NULL)
        exit(1);
    
    // Determina se a agenda já está cheia ou não
    rewind(fptr);
    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) / sizeof(contato) >= 100)
    {
        printf("Espaco insuficiente\n");
        fclose(fptr);
        return;
    }
    
    // Grava o contato na agenda
    contato tmp;
    scanf("%s %i %s", tmp.nome, &tmp.idade, tmp.telefone);
    fwrite(&tmp, sizeof(contato), 1, fptr);
    
    fclose(fptr);
    printf("Registro %s %i %s inserido\n", tmp.nome, tmp.idade, tmp.telefone);
    return;
}

void alterar(char *arquivo)
{
    scanf("\n");
    
    // Determina o tamanho e quantidade de structs do arquivo
    FILE *fptr1 = fopen(arquivo, "rb");
    if (fptr1 == NULL)
        exit(1);
    fseek(fptr1, 0, SEEK_END);
    unsigned int size = ftell(fptr1);
    int n_structs = size / sizeof(contato);
    rewind(fptr1);

    // Lê o arquivo inteiro em um buffer temporário
    contato tmp[n_structs];
    fread(tmp, sizeof(contato), n_structs, fptr1);
    fclose(fptr1);
    
    // Recebe a informação e altera o buffer temporário
    contato match;
    scanf("%s %i %s", match.nome, &match.idade, match.telefone);
    for (int i = 0; i < n_structs; i++)
    {
        if (strcmp(match.nome, tmp[i].nome) == 0)
        {
            tmp[i] = match;
            printf("Registro %s %i %s alterado\n", tmp[i].nome, tmp[i].idade, tmp[i].telefone);
        }
    }
    
    // Reescreve o arquivo usando o buffer temporário alterado
    FILE *fptr2 = fopen(arquivo, "wb");
    if (fptr2 == NULL)
        exit(1);
    for (int i = 0; i < 100; i++)
    {
        fwrite(&tmp[i], sizeof(contato), 1, fptr2);
    }

    fclose(fptr2);
    return;
}

void excluir (char *arquivo)
{
    scanf("\n");
    
    // Recebe a pessoa que deseja excluir
    char pessoa[50];
    fgets(pessoa, 50, stdin);
    pessoa[strlen(pessoa) - 1] = '\0';
    
    // Abre o arquivo e determina seu tamanho
    FILE *fptr1 = fopen(arquivo, "rb");
    if (fptr1 == NULL)
        exit(1);
    fseek(fptr1, 0, SEEK_END);
    unsigned int size = ftell(fptr1);
    int n_structs = size / sizeof(contato);
    rewind(fptr1);

    // Determina se o registro existe usando um buffer temporário
    int achou = 0;
    contato tmp[n_structs];
    for (int i = 0; i < n_structs; i++)
    {
        fread(&tmp[i], sizeof(contato), 1, fptr1);
        if (strcmp(pessoa, tmp[i].nome) == 0)
            achou = 1;
    }
    if (achou == 0)
    {
        printf("Registro %s invalido\n", pessoa);
        return;
    }
    fclose(fptr1);
    
    // Reescreve o arquivo com base no buffer temporário, exceto à pessoa excluída
    FILE *fptr2 = fopen(arquivo, "wb");
    if (fptr2 == NULL)
        exit(1);
    for (int i = 0; i < n_structs; i++)
    {
        if (strcmp(pessoa, tmp[i].nome) != 0)
        {
            fwrite(&tmp[i], sizeof(contato), 1, fptr2);
        }
        else
        {
            printf("Registro %s %i %s excluido\n", tmp[i].nome, tmp[i].idade, tmp[i].telefone);
        }
    }
    fclose(fptr2);
    return;
}

void exibir(char *arquivo)
{
    scanf("\n");
    
    // Pede pela pessoa que quer exibir
    char procurado[50];
    fgets(procurado, 50, stdin);
    procurado[strlen(procurado) - 1] = '\0';
    
    FILE *fptr = fopen(arquivo, "rb");
    if (fptr == NULL)
        exit(1);
    
    // Determina a quantidade de structs do arquivo
    fseek(fptr, 0, SEEK_END);
    unsigned int size = ftell(fptr);
    int n_structs = size / sizeof(contato);
    rewind(fptr);
    
    // Procura pela pessoa requisitada e exibe se encontrar
    contato tmp[n_structs];
    for (int i = 0; i < n_structs; i++)
    {
        fread(&tmp[i], sizeof(contato), 1, fptr);
        if (strcmp(procurado, tmp[i].nome) == 0)
        {
            printf("Registro %s %i %s exibido\n", tmp[i].nome, tmp[i].idade, tmp[i].telefone);
            return;
        }
    }
    
    fclose(fptr);
    printf("Registro %s invalido\n", procurado);
    return;
}