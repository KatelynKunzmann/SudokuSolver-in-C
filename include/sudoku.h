#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLS;

typedef struct Box
{
    struct Box *next;
} Box;

typedef struct Square
{
    int num;
    Box *box;

    /* [0] [1] [2] [3] [4] [5] [6] [7] [8] */
    /* [0] [0] [0] [0] [0] [0] [0] [0] [0] */
    /* Can it be a 0 -> False, can it be a 1 -> False, etc */
    int possible[9];
    int solvable;
    int row;
    int col;
} Square;

int **createPuzzle();
void printPuzzle(Square ***puzzle);
Square ***setUpPuzzle(int **puzzle);
void intiBoolToTrue(Square ***sudoku, int row, int col);
int updateSudoku(Square ***sudoku, int row, int col);
int checkPuzzle(Square ***sudoku);
int solveSquare(Square *square);

#endif