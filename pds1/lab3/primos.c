#include <stdio.h>

int main(void)
{
    int A;
    int B;
    int factors = 0; // A prime number is a number with more than 2 factors
    scanf("%i %i", &A, &B);
    
    while (A <= B)
    {
        // Counting the factors
        for (int i = 1; i <= A; i++)
        {
            if (A % i == 0)
            {
                factors++;
            }
        }
        // Checking if it's prime based on the number of factors
        if (factors == 2)
        {
            printf("%d\n", A);
        }
        // Uploading variables
        A++;
        factors = 0;
    }
    
    return 0;
}