#include <iostream>

double valor_total(int horas);
double impostos(double salario, int dependentes);

int main()
{
    // Inputs provenientes do usuário para calcular sua renda
    int horas {};
    std::cout << "Horas trabalhadas: ";
    std::cin >> horas;

    int dependentes {};
    std::cout << "Número de dependentes: ";
    std::cin >> dependentes;

    // Chamada de funções e prints ao usuário
    double valor_salario { valor_total(horas) };
    double valor_impostos { impostos(valor_salario, dependentes) };

    std::cout << "Valor bruto: " << valor_salario << std::endl;
    std::cout << "Impostos retidos: " << valor_impostos << std::endl;
    std::cout << "Pagamento líquido: " << valor_salario - valor_impostos << std::endl;
}

double valor_total(int horas)
{
    double salario {};

    // Prevê o valor do salário do usuário com base em se houve horas extras
    if (horas <= 40)
    {
        salario = horas * 16.78;
    }
    else
    {
        salario = horas * 16.78;
        salario += ((horas - 40) * (16.78 * 1.5));
    }

    return salario;
}

double impostos(double salario, int dependentes)
{
    double total_impostos {};

    // Cálculo dos impostos e print
    double previdencia { salario * 0.06 };
    std::cout << "Taxa da Previdência Social: " << previdencia << std::endl;

    double irf { salario * 0.14 };
    std::cout << "Imposto de Renda Federal: " << irf << std::endl;
    
    double estadual { salario * 0.05 };
    std::cout << "Imposto Estadual: " << estadual << std::endl;

    double sindicato { 10 };
    std::cout << "Valor do Sindicato: " << sindicato << std::endl;

    double valor_dependentes {};
    if (dependentes >= 3)
    {
        valor_dependentes += 35;
    }

    return previdencia + irf + estadual + sindicato + valor_dependentes;
}