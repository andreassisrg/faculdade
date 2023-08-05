#include <stdio.h>

int main(void)
{
    // Número de alunos em aeds
    int num_aeds;
    scanf("%i", &num_aeds);
    
    // Matrícula de alunos de aeds
    int alunos_aeds[num_aeds];
    for (int i = 0; i < num_aeds; i++)
    {
        scanf("%i\n", &alunos_aeds[i]);
    }
    
    // Número de alunos em cálculo
    int num_calc;
    scanf("%i", &num_calc);
    
    // Matrícula de alunos em cálculo
    int alunos_calc[num_calc];
    for (int i = 0; i < num_calc; i++)
    {
        scanf("%i", &alunos_calc[i]);
    }
    
    // Comparando ambos vetores
    for (int i = 0; i < num_aeds; i++)
    {
        for (int j = 0; j < num_calc; j++)
        {
            if (alunos_aeds[i] == alunos_calc[j])
            {
                printf("%i\n", alunos_aeds[i]);
            }
        }
    }
    
    return 0;
}