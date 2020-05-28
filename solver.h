//
// Created by Can Arseven on 15/07/2018.
//

#ifndef SUDOKU_SOLVER_SUDOKU_H_
#define SUDOKU_SOLVER_SUDOKU_H_

#define SIZE 9
#define SQRT_SIZE 3

void init(int begin[SIZE][SIZE]);
void print();
int checkValueInMatrix(int value, int row, int col);
int setValueInMatrix(int value, int row, int col);
int removeValueFromMatrix(int row, int col);
int getValueFromMatrix(int row, int col);
int solve(int row, int col);

#endif SUDOKU_SOLVER_SUDOKU_H_
