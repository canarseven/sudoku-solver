//
// Created by Can Arseven on 15/07/2018.
//

#include <stdio.h>
#include "solver.h"

void readSudoku(char * filepath)
{
    FILE * fp;
    char line[19];
    int initialMatrix[SIZE][SIZE];

    fp = fopen(filepath, "r");

    //Read Sudoku from txt line by line and store it in the initialMatrix
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        int j = 0;
        while(j < sizeof(line)) {
            if (j % 2 == 0) {
                int num = line[j] - '0';
                initialMatrix[i][j/2] = num;
            }
            j++;
        }
        i++;
    }
    fclose(fp);

    init(initialMatrix);
    printf("||\t\t\t  Initial Sudoku \t\t   ||\n");
    print();
}

