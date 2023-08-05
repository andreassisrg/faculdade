#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **cria_tabuleiro(int dim);
bool mov_valid(int x_dest, int y_dest, int x_pulado, int y_pulado, char tipo, char tipo_oposto, char **tabuleiro, int dim);
void reseta(char **tabuleiro, int dim, char target, char original);
int max(int a, int b);
int move_peca(int x, int y, char tipo, char tipo_oposto, char **tabuleiro, int dim);
void lei_da_maioria(char **tabuleiro, int dim);
void free_matrix(char **ptr, int dim);

int main(void)
{
    // Tamanho do tabuleiro
    int N;
    scanf("%d", &N);

    // Cria e preenche tabuleiro
    char **tab1 = cria_tabuleiro(N);

    // Executa algoritmo para prever "Lei da Maioria"
    // Prevê apenas o movimento das peças brancas
    lei_da_maioria(tab1, N);

    // Libera memória usada no tabuleiro
    free_matrix(tab1, N);
}

char **cria_tabuleiro(int dim)
{
    // Cria matrix por meio de ponteiro duplo e vetores com ponteiro simples
    char **mat = (char **) malloc(dim * sizeof(char *));
    for (int i = 0; i < dim; i++)
    {
        mat[i] = (char *) malloc((dim + 2) * sizeof(char)); // dim + '\n' e '\0'
    }
    // Lê matrix do prompt
    scanf("\n");
    for (int i = 0; i < dim; i++)
    {
        fgets(mat[i], dim + 2, stdin);
        if (mat[i][strlen(mat[i])-1] = '\n')
            mat[i][strlen(mat[i])-1] = '\0';
    }

    return mat;
}

bool mov_valid(int x_dest, int y_dest, int x_pulado, int y_pulado, char tipo, char tipo_oposto, char **tabuleiro, int dim)
{
    /* Uma peça pode se mover se em sua diagonal há o tipo oposto seguido de um espaço vazio,
       porém não pode se mover se seu salto resultará fora do tabuleiro, e finalmente, também
       não pode comer uma peça já comida e marcada por '!' */

    // Checa se coordenadas pretendidas estão dentro do tabuleiro
    if (x_dest >= dim || y_dest >= dim || x_dest < 0 || y_dest < 0)
        return false;

    // Checa se a peça pulada é do tipo oposto
    if (tabuleiro[x_pulado][y_pulado] != tipo_oposto)
        return false;

    // Checa se a casa destinada está livre
    if (tabuleiro[x_dest][y_dest] != 'o')
        return false;

    // Checa se a peça já foi comida
    if (tabuleiro[x_pulado][y_pulado] == '!')
        return false;

    // Caso o movimento seja possível, marca a peça a ser comida e retorna true
    tabuleiro[x_pulado][y_pulado] = '!';
    return true;
}

void reseta(char **tabuleiro, int dim, char target, char original)
{
    // Reseta o tabuleiro ao original: as peças comidas e marcadas por "target" são recuperadas
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (tabuleiro[i][j] == target)
            {
                tabuleiro[i][j] = original;
            }
        }
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int move_peca(int x, int y, char tipo, char tipo_oposto, char **tabuleiro, int dim)
{
    int count = 0;
    
    // Cima direita
    if (mov_valid(x+2, y+2, x+1, y+1, tipo, tipo_oposto, tabuleiro, dim))
    {
        count = max(count, 1 + move_peca(x+2, y+2, tipo, tipo_oposto, tabuleiro, dim));
        tabuleiro[x+1][y+1] = tipo_oposto;
    }
    
    // Cima esquerda
    if (mov_valid(x-2, y+2, x-1, y+1, tipo, tipo_oposto, tabuleiro, dim))
    {
        count = max(count, 1 + move_peca(x-2, y+2, tipo, tipo_oposto, tabuleiro, dim));
        tabuleiro[x-1][y+1] = tipo_oposto;
    }
    
    // Baixo direita
    if (mov_valid(x+2, y-2, x+1, y-1, tipo, tipo_oposto, tabuleiro, dim))
    {
        count = max(count, 1 + move_peca(x+2, y-2, tipo, tipo_oposto, tabuleiro, dim));
        tabuleiro[x+1][y-1] = tipo_oposto;
    }
    
    // Baixo esquerda
    if (mov_valid(x-2, y-2, x-1, y-1, tipo, tipo_oposto, tabuleiro, dim))
    {
        count = max(count, 1 + move_peca(x-2, y-2, tipo, tipo_oposto, tabuleiro, dim));
        tabuleiro[x-1][y-1] = tipo_oposto;
    }
    
    return count;
}

void lei_da_maioria(char **tabuleiro, int dim)
{
    // Cria vetor que armazenará resultado
    int **res = NULL;
    int n;
    int count = 0;

    // Percorre tabuleiro e prevê o movimento de cada peça
    for (int i = 0; i < dim; i++)
    {
        // Sentido crescente do tabuleiro
        if (i % 2 == 0)
        {
            for (int j = 0; j < dim; j++)
            {
                n = 0;
                if (tabuleiro[i][j] == 'b')
                {
                    tabuleiro[i][j] = 'o';
                    n = move_peca(i, j, 'b', 'p', tabuleiro, dim);
                    reseta(tabuleiro, dim, '!', 'p');
                    tabuleiro[i][j] = 'b';
                }
                if (n != 0)
                {
                    // Aloca memória para o resultado obtido
                    res = (int **) realloc(res, (count + 1) * sizeof(int *));
                    res[count] = (int *) malloc(3 * sizeof(int));

                    // Armazena entrada
                    res[count][0] = i;
                    res[count][1] = j;
                    res[count][2] = n;
                    count++;
                }
            }
        }
        // Sentido decrescente do tabuleiro
        else
        {
            for (int j = dim - 1; j >= 0; j--)
            {
                n = 0;
                if (tabuleiro[i][j] == 'b')
                {
                    tabuleiro[i][j] = 'o';
                    n = move_peca(i, j, 'b', 'p', tabuleiro, dim);
                    reseta(tabuleiro, dim, '!', 'p');
                    tabuleiro[i][j] = 'b';
                }
                if (n != 0)
                {
                    // Aloca memória para o resultado obtido
                    res = (int **) realloc(res, (count + 1) * sizeof(int *));
                    res[count] = (int *) malloc(3 * sizeof(int));

                    // Armazena entrada
                    res[count][0] = i;
                    res[count][1] = j;
                    res[count][2] = n;
                    count++;
                }
            }
        }
    }
    // Imprime resultado e libera memória do vetor "res"
    int maior = res[0][2];
    int ind_maior = 0;
    for (int i = 0; i < count; i++)
    {
        if (res[i][2] > maior)
        {
            maior = res[i][2];
            ind_maior = i;
        }
    }
    printf("%d %d %d\n", res[ind_maior][0], res[ind_maior][1], res[ind_maior][2]);
    for (int i = 0; i < count; i++)
    {
        printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
        free(res[i]);
    }
    free(res);
}

void free_matrix(char **ptr, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        free(ptr[i]);
    }
    free(ptr);
}