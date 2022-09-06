#include "../include/sudoku.h"

int solveSquare(Square *square)
{
    int x;

    for (x = 0; x < SIZE_ROWS; x++)
    {
        if (*square->possible == true)
        {
            square->num = x + 1;
            square->solvable = 0;
            UNSOLVED--;
        }
    }

    return 1;
}