#include <iostream>

int main()
{
    // Taxas de Juros e Prestações, e valor a ser pago
    const double taxa_juros { 0.015};
    const double valor_prestacao { 50 };
    double divida { 1000 };

    // Loop para averiguar quantidade de meses e valor pago em juros
    int meses {};
    double juros_pagos {};
    while (divida > 0)
    {
        double juros_atual = taxa_juros * divida;
        double valor_mensal = valor_prestacao - juros_atual;

        meses++;
        juros_pagos += juros_atual;
        divida -= valor_mensal;
    }

    std::cout << "Número de Meses Usados: " << meses << std::endl;
    std::cout << "Valor Pago em Juros: " << juros_pagos << std::endl;
}