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

    printPuzzle(puzzle);

    sudoku = setUpPuzzle(puzzle);

    checkPuzzle(sudoku);

    return 0;
}