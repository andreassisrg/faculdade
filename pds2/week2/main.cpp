#include <iostream>
#include <string>

void ex01();
void ex02();
void ex03();
void ex04();
void ex05();
void ex06();

int main()
{
    ex03();
}

void ex01()
{
    char *atv1;
    char **atv2;
    char *atv3[100];
    char atv4[100];
    int * const atv5 { }; // Requer um inicializador, logo { } inicializa a 0
    const int *atv6;
}

void ex02()
{
    std::string explicacao
    {
        "Um ponteiro constante significa que o valor do endereço de memória não pode ser modificado, porém o valor para o qual ele aponta pode. \
        \n De forma contrária, um ponteiro para um tipo constante pode ter seu endereço de memória modificado, mas o valor para o qual ele aponta não."
    };

    std::cout << explicacao << std::endl;
}

void ex03()
{
    // Array de vetor de ponteiros para inteiros
    int LENGTH { 3 };
    int *numeros[LENGTH];

    // Armazenamento
    for (int i = 0; i < LENGTH; i++)
    {
        std::cout << "Digite o " << i + 1 << "º número" << std::endl;
        std::cin >> *numeros[i];
    }

    // Impressão na tela
    /*
    for (int i = LENGTH; i > 0; i--)
    {
        std::cout << *numeros[i] << std::endl;
    }
    */
}

void ex04()
{
    struct Funcionario
    {
        std::string name;
        std::string address;
        std::string zipcode;
    };
    
    int N { };
    std::cin >> N;

    // alocação de memoria e preenchimento de dados
}