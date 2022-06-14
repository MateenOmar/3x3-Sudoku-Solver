#include <stdio.h>

int find_empty_slot(int sudoku[9][9], int *row, int *col)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == 0)
            {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }

    return 0;
}

int check_row(int sudoku[9][9], int row, int val)
{
    for (int j = 0; j < 9; j++)
    {
        if (sudoku[row][j] == val)
        {
            return 0;
        }
    }

    return 1;
}

int check_col(int sudoku[9][9], int col, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][col] == val)
        {
            return 0;
        }
    }

    return 1;
}

int check_3x3_box(int sudoku[9][9], int rowStart, int colStart, int val)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[rowStart + i][colStart + j] == val)
            {
                return 0;
            }
        }
    }

    return 1;
}

int valid_move(int sudoku[9][9], int row, int col, int val)
{
    return check_row(sudoku, row, val) && check_col(sudoku, col, val) && check_3x3_box(sudoku, row - (row % 3), col - (col % 3), val);
}

int solver(int sudoku[9][9])
{

    int row;
    int col;

    if (!find_empty_slot(sudoku, &row, &col))
    {
        return 1;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (valid_move(sudoku, row, col, i))
        {
            sudoku[row][col] = i;

            if (solver(sudoku))
            {
                return 1;
            }

            sudoku[row][col] = 0;
        }
    }

    return 0;
}

void solve_sudoku(int sudoku[9][9])
{
    solver(sudoku);
}

void print_sudoku(int sudoku[9][9])
{
    printf("The Sudoku contains:\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d  ", sudoku[i][j]);
        }
        printf("\n");
    }
}
