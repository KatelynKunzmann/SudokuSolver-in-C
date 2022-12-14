#include "../include/sudoku.h"

// define externs here
int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLS = 9;

int main()
{
    int **puzzle;
    Square ***sudoku;

    puzzle = createPuzzle();

    sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku);

    checkPuzzle(sudoku);

    printf("\n\n");

    printPuzzle(sudoku);

    return 0;
}