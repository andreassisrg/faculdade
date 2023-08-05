#include <stdio.h>

int eh_bissexto(int ano);
unsigned long int n_dias(int dias, int meses, int anos);

int array_normal[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int array_bissexto[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
    unsigned long int referencia = n_dias(17, 9, 2020);
    int dia, mes, ano;
    while(scanf("%d %d %d", &dia, &mes, &ano) != EOF)
    {
        unsigned long int ano_input = n_dias(dia, mes, ano);
        printf("%lu\n", referencia - ano_input + 1);
    }
}

int eh_bissexto(int ano)
{
    if (ano % 4 != 0)
        return 0;
    if (ano % 100 == 0 && ano % 400 != 0)
        return 0;
    return 1;
}

unsigned long int n_dias(int dias, int meses, int anos)
{
    unsigned long int soma = 0;
    int bissexto = eh_bissexto(anos);
    
    // Somando os dias
    soma += dias;
    
    // Somando os meses
    for (int i = 0; i < meses - 1; i++)
    {
        if (bissexto == 1)
        {
            soma += array_bissexto[i];
        }
        else
        {
            soma += array_normal[i];
        }
    }
    
    // Somando os anos
    for (int i = 0; i < anos; i++)
    {
        if (eh_bissexto(i))
        {
            soma += 366;
        }
        else
        {
            soma += 365;
        }
    }
    
    return soma;
}