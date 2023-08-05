#include <stdio.h>

#define B_LEN 9
#define G_LEN 3

typedef struct
{
    int matrix[B_LEN][B_LEN];
} board;

typedef struct
{
    int matrix[G_LEN][G_LEN];
} grid;

int check_lines(board board);
int check_grids(board board);
int check_board(board board);

int main(void)
{
    // Getting the number of boards
    int n_boards;
    scanf(" %d\n", &n_boards);

    // Getting all the boards
    int all_boards[B_LEN*n_boards][B_LEN];
    for (int rows = 0; rows < B_LEN*n_boards; rows++)
    {
        for (int cols = 0; cols < 9; cols++)
        {
            scanf("%d", &all_boards[rows][cols]);
        }
    }

    // Separating each board
    board boards[n_boards];
    for (int i = 0; i < n_boards; i++)
    {
        for (int j = 0 + 9*i; j < 9+9*i; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                boards[i].matrix[j-9*i][k] = all_boards[j][k];
            }
        }
    }
    // Boards is an array containing all the 9x9 sudoku boards prompted by the user

    for (int i = 0; i < n_boards; i++)
    {
        check_board(boards[i]);
    }
    return 0;
}

int check_lines(board board)
{
    // Check horizontal lines
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                if (j == k)
                {
                    continue;
                }
                else
                {
                    if (board.matrix[i][j] == board.matrix[i][k])
                    {
                        return 1;
                    }
                }
            }
        }
    }
    // Check vertical lines
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                if (j == k)
                {
                    continue;
                }
                else
                {
                    if (board.matrix[j][i] == board.matrix[k][i])
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int check_grids(board board)
{
    // Creating an array of 9 3x3 grids
    grid grids[9];

    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    grids[l+3*k].matrix[i][j] = board.matrix[i+3*k][j+3*l];
                }
            }
        }
    }
    
    for (int ind = 0; ind < 9; ind++)
    {
        // Checking a grid for repeated numbers
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        if (i == k && j == l)
                        {
                            continue;
                        }
                        else
                        {
                            if (grids[ind].matrix[i][j] == grids[ind].matrix[k][l])
                            {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int check_board(board board)
{
    if (check_lines(board) == 0 && check_grids(board) == 0)
    {
        printf("CORRETO\n");
        return 0;
    }
    else
    {
        printf("INCORRETO\n");
        return 1;
    }
}