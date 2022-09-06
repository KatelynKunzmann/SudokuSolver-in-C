#include "../include/sudoku.h"

void initBoolToTrue(Square ***sudoku, int row, int col)
{
    int x;
    for (x = 0; x < SIZE_ROWS; x++)
    {
        sudoku[row][col]->possible[x] = true;
    }
}

Square ***setUpPuzzle(int **puzzle)
{
    Square ***sudoku;
    int i, j;

    sudoku = (Square ***)malloc(sizeof(Square **) * 9);

    // Looping through rows (i)
    for (i = 0; i < SIZE_ROWS; i++)
    {
        sudoku[i] = (Square **)malloc(sizeof(Square *) * 9);

        // Looping through columns (j)
        for (j = 0; j < SIZE_COLS; j++)
        {
            sudoku[i][j] = (Square *)malloc(sizeof(Square) * 9);
            sudoku[i][j]->num = puzzle[i][j];
            sudoku[i][j]->row = i;
            sudoku[i][j]->col = j;
            // sudoku[i][j]->box = i%3;

            initBoolToTrue(sudoku, i, j);
        }
    }

    // Looping through rows (i)
    for (i = 0; i < SIZE_ROWS; i++)
    {
        // Looping through columns (j)
        for (j = 0; j < SIZE_COLS; j++)
        {
            if (sudoku[i][j]->num != 0)
            {
                sudoku[i][j]->solvable = 0;
                updateSudoku(sudoku, i, j);
                UNSOLVED--;
            }
        }
    }
    return sudoku;
}

int updateSudoku(Square ***sudoku, int row, int col)
{
    int x;
    int number = sudoku[row][col]->num;

    for (x = 0; x < SIZE_ROWS; x++)
    {
        if (sudoku[x][col]->possible[number - 1] == false)
        {
            sudoku[x][col]->solvable--;
        }
        sudoku[x][col]->possible[number - 1] = true;
    }

    for (x = 0; x < SIZE_COLS; x++)
    {
        if (sudoku[row][x]->possible[number - 1] == false)
        {
            sudoku[row][x]->solvable--;
        }
        sudoku[row][x]->possible[number - 1] = true;
    }

    return 1;
}

int checkPuzzle(Square ***sudoku)
{
    int i, j, x;

    // Looping through rows (i)
    for (i = 0; i < SIZE_ROWS; i++)
    {

        // Looping through columns (j)
        for (j = 0; j < SIZE_COLS; j++)
        {
            if (sudoku[i][j]->solvable == 1)
            {
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku, i, j);
            }
        }
    }
    return 1;
}

int **createPuzzle()
{
    int **puzzle;
    int i, j;
    int arr[9][9] = {0, 1, 9, 0, 0, 2, 0, 0, 0,
                     4, 7, 0, 6, 9, 0, 0, 0, 1,
                     0, 0, 0, 4, 0, 0, 0, 9, 0,

                     8, 9, 4, 5, 0, 7, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 2, 0, 1, 9, 5, 8,

                     0, 5, 0, 0, 0, 6, 0, 0, 0,
                     6, 0, 0, 0, 2, 8, 0, 7, 9,
                     0, 0, 0, 1, 0, 0, 8, 6, 0};

    // allocate memory for all arrays
    puzzle = (int **)malloc(sizeof(int *) * 9);

    for (i = 0; i < SIZE_ROWS; i++)
    {
        puzzle[i] = (int *)malloc(sizeof(int) * 9);

        for (j = 0; j < SIZE_COLS; j++)
        {
            puzzle[i][j] = arr[i][j];
        }
    }

    return puzzle;
}

void printPuzzle(int **puzzle)
{
    int i, j;
    printf("-------------------------------\n");
    for (i = 0; i < SIZE_ROWS; i++)
    {
        printf("|");
        for (j = 0; j < SIZE_COLS; j++)
        {
            printf(" %d ", puzzle[i][j]);

            if ((j + 1) % 3 == 0)
                printf("|");
        }
        printf(" ");
        printf("\n");
        if ((i + 1) % 3 == 0)
            printf("-------------------------------\n");
    }
}
