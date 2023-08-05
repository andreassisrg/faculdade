#include <stdio.h>
#include <string.h>

#define DEBUG 0

typedef struct
{
    char nome[50];
    unsigned int idade;
    float salario;
}
registro;

int main(void)
{
    registro registros[4];
    char buffer[100];
    int cont = 0;
    
    do
    {
        fgets(buffer, 100, stdin);
        
        if (!strcmp(buffer, "inserir\n"))
        {
            if (DEBUG) { puts("Entrei em inserir"); }
            
            if (cont < 4)
            {
                scanf("%s %u %f%*1[\n]", registros[cont].nome, &registros[cont].idade, &registros[cont].salario);
                printf("Registro %s %u %.2f inserido\n", registros[cont].nome, registros[cont].idade, registros[cont].salario);
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
                    printf("Registro %s %u %.2f\n", registros[i].nome, registros[i].idade, registros[i].salario);
                    achou = 1;
                }
            }
            if (!achou) { puts("Registro ausente"); }
        }
    }
    while (strcmp(buffer, "\n") != 0);
    
    return 0;
}