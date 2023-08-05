#include <stdio.h>
#include <string.h>

#define DEBUG 0

typedef struct
{
    char rua[50];
    unsigned int numero;
    char estado[50];
}
endereco;

typedef struct
{
    char nome[50];
    unsigned int idade;
    float salario;
    endereco endereco;
}
registro;

int main(void)
{
    registro registros[5];
    char buffer[100];
    int cont = 0;
    
    do
    {
        fgets(buffer, 100, stdin);
        
        if (!strcmp(buffer, "inserir\n"))
        {
            if (DEBUG) { puts("Entrei em inserir"); }
            
            if (cont < 5)
            {
                scanf("%s %u %f %s %u %s%*1[\n]", registros[cont].nome, &registros[cont].idade, &registros[cont].salario,
                registros[cont].endereco.rua, &registros[cont].endereco.numero, registros[cont].endereco.estado);
                printf("Registro %s %u %.2f %s %u %s inserido\n", registros[cont].nome, registros[cont].idade, registros[cont].salario,
                registros[cont].endereco.rua, registros[cont].endereco.numero, registros[cont].endereco.estado);
                cont++;
            }
            else
            {
                puts("Espaco insuficiente");
            }
        }
        if (!strcmp(buffer, "mostrar\n"))
        {
            if (DEBUG) { puts("Entrei em mostrar"); }
            
            fgets(buffer, 100, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            int achou = 0;
            for (int i = 0; i < cont; i++)
            {
                if (strcmp(buffer, registros[i].nome) == 0)
                {
                    printf("Registro %s %u %.2f %s %u %s\n", registros[i].nome, registros[i].idade, registros[i].salario,
                    registros[i].endereco.rua, registros[i].endereco.numero, registros[i].endereco.estado);
                    achou = 1;
                }
            }
            if (!achou) { puts("Registro ausente"); }
        }
        if (!strcmp(buffer, "alterar\n"))
        {
            int achou = 0;
            registro tmp;
            scanf("%s %u %f %s %u %s%*1[\n]", tmp.nome, &tmp.idade, &tmp.salario, tmp.endereco.rua, &tmp.endereco.numero, tmp.endereco.estado);
            for (int i = 0; i < cont; i++)
            {
                if (strcmp(tmp.nome, registros[i].nome) == 0)
                {
                    registros[i] = tmp;
                    achou = 1;
                    printf("Registro %s %u %.2f %s %u %s alterado\n", registros[i].nome, registros[i].idade, registros[i].salario,
                    registros[i].endereco.rua, registros[i].endereco.numero, registros[i].endereco.estado);
                }
            }
            if (!achou) { puts("Registro ausente para alteracao"); }
        }
    }
    while (strcmp(buffer, "\n") != 0);
    
    return 0;
}