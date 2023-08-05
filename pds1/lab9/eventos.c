#include <string.h>
#include <stdio.h>

enum Meses{Jan = 1, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez};

typedef struct
{
    int dia;
    enum Meses mes;
    int ano;
}
Data;

typedef struct
{
    char nome[100];
    char local[100];
    Data data;
}
Evento;

void cadastrar_eventos(Evento agenda[], int n);
void imprimir_eventos(Evento agenda[], Data d, int n);

int main(void)
{
    // Número de registros
    int n;
    scanf("%d\n", &n);
    
    // Cadastrando todos eventos do usuário
    Evento registro[n];
    cadastrar_eventos(registro, n);
    
    // Data provida pelo usuário
    Data d;
    scanf("%d %u %d", &d.dia, &d.mes, &d.ano);
    
    // Compara eventos com data pedida
    imprimir_eventos(registro, d, n);
}

void cadastrar_eventos(Evento agenda[], int n)
{
    // Pega todos os n registros no prompt
    for (int i = 0; i < n; i++)
    {
        scanf("\n");
        scanf("%s %s %d %u %d", agenda[i].nome, agenda[i].local,
        &agenda[i].data.dia, &agenda[i].data.mes, &agenda[i].data.ano);
    }
}

void imprimir_eventos(Evento agenda[], Data d, int n)
{
    int achou = 0;
    for (int i = 0; i < n; i++)
    {
        if (agenda[i].data.dia == d.dia && agenda[i].data.mes == d.mes && agenda[i].data.ano == d.ano)
        {
            achou = 1;
            printf("%s %s\n", agenda[i].nome, agenda[i].local);
        }
    }
    
    if (achou == 0)
        printf("Nenhum evento encontrado!");
}