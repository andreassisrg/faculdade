#include <iostream>
#include <string>

void ex01();
void ex02();
void ex03();
void ex04();
void ex05();
//void fill_data(EmployeeData *ptr, int N);

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
        \n De forma contrária, um ponteiro para um tipo constante aponta para um dado que não pode ser modificado através desse ponteiro, mas que \
        \n pode ser usado para apontar para outros dados."
    };

    std::cout << explicacao << std::endl;
}

void ex03()
{
    // Array de vetor de ponteiros para inteiros
    int LENGTH { 3 };
    int *numeros;
    numeros = new int[LENGTH];

    // Armazenamento
    for (int i = 0; i < LENGTH; i++)
    {
        std::cout << "Digite o " << i + 1 << "º número" << std::endl;
        std::cin >> numeros[i];
    }

    std::cout << "\n"; // Apenas para formatação

    // Impressão na tela
    for (int i = LENGTH - 1; i >= 0; i--)
    {
        std::cout << numeros[i] << std::endl;
    }

   // Desalocaçao
   delete[] numeros;
}

void ex04()
{
    // Declaração da Struct e N
    struct EmployeeData
    {
        std::string name;
        std::string address;
        std::string zipcode;
    };
    
    int N { };
    std::cout << "Digite o número de funcionários: ";
    std::cin >> N;

    // Alocação de memória
    struct EmployeeData *funcionarios;
    funcionarios = new struct EmployeeData[N];

    // Preenchimento de dados
    for (int i = 0; i < N; i++)
    {
        std::cout << "Digite os dados do funcionário " << i + 1 << std::endl;
        
        std::cout << "Nome: ";
        getline(std::cin >> std::ws, funcionarios[i].name);
        
        std::cout << "Endereço: ";
        getline(std::cin >> std::ws, funcionarios[i].address);
        
        std::cout << "CEP: ";
        getline(std::cin >> std::ws, funcionarios[i].zipcode);
    }

    // Impressão de dados
    for (int i = 0; i < N; i++)
    {
        std::cout << "\n Funcionário " << i + 1 << std::endl;
        std::cout << "Nome: " << funcionarios[i].name << std::endl;
        std::cout << "Endereço: " << funcionarios[i].address << std::endl;
        std::cout << "CEP: " << funcionarios[i].zipcode << std::endl;
    }

    // Desalocação de memória
    delete[] funcionarios;
}

void ex05()
{
    // Declaração da Struct e N
    struct EmployeeData
    {
        std::string name;
        std::string address;
        std::string zipcode;
    };
    
    int N { };
    std::cout << "Digite o número de funcionários: ";
    std::cin >> N;

    // Alocação de memória
    struct EmployeeData *funcionarios;
    funcionarios = new struct EmployeeData[N];

    // Desalocação de memória
    delete[] funcionarios;
}

/*
void fill_data(EmployeeData *ptr, int N)
{
        // Preenchimento de dados
    for (int i = 0; i < N; i++)
    {
        std::cout << "Digite os dados do funcionário " << i + 1 << std::endl;
        
        std::cout << "Nome: ";
        getline(std::cin >> std::ws, funcionarios[i].name);
        
        std::cout << "Endereço: ";
        getline(std::cin >> std::ws, funcionarios[i].address);
        
        std::cout << "CEP: ";
        getline(std::cin >> std::ws, funcionarios[i].zipcode);
    }

    // Impressão de dados
    for (int i = 0; i < N; i++)
    {
        std::cout << "\n Funcionário " << i + 1 << std::endl;
        std::cout << "Nome: " << funcionarios[i].name << std::endl;
        std::cout << "Endereço: " << funcionarios[i].address << std::endl;
        std::cout << "CEP: " << funcionarios[i].zipcode << std::endl;
    }
}
*/