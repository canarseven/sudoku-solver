//
// Created by Can Arseven on 15/07/2018.
//

#include <stdio.h>
#include "solver.h"
#include "reader.h"

int main(int argc, char * const argv[])
{
    //Reads the matrix, stores it in glob. variable and prints it.
    readSudoku(argv[1]);

    //Solve the matrix and print the solution
    printf("||\t\t\t  Solved Sudoku \t\t   ||\n");
    solve(0, 0);
    print();

    //Stop the program until input to view the result
    int x;
    scanf("%i", &x);
    return 0;
}