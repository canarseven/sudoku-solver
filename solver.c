//
// Created by Can Arseven on 15/07/2018.
//

#include "solver.h"
#include <stdio.h>
#include <memory.h>


int matrix[SIZE][SIZE];
int initial[SIZE][SIZE];


/* Initializes the Sudoku Matrix. The matrix initial keeps
 * the original start value for figuring out if a value
 * is fixed or can be changed. */
void init(int begin[SIZE][SIZE])
{
	memcpy(matrix, begin, SIZE * SIZE * sizeof(int));
	memcpy(initial, begin, SIZE * SIZE * sizeof(int));
}

/* Prints the sudoku matrix */
void print()
{
	int row, col;
	// print the first line
	printf("||");
	for (col = 0; col < SIZE - 1; col++)
	{
		if (col % SQRT_SIZE == SQRT_SIZE - 1)
			printf("===++");
		else
			printf("===+");
	}
	printf("===||\n");
	for (row = 0; row < SIZE; row++)
	{
		for (col = 0; col < SIZE; col++)
		{
			if (col % SQRT_SIZE == 0)
				printf("|| ");
			else
				printf("| ");
			if (matrix[row][col] == 0)
				printf("  ");
			else
				printf("%d ", matrix[row][col]);
		}
		printf("||\n||");
		if (row % SQRT_SIZE == SQRT_SIZE - 1)
		{
			for (col = 0; col < SIZE - 1; col++)
			{
				if (col % SQRT_SIZE == SQRT_SIZE - 1)
					printf("===++");
				else
					printf("===+");
			}
			printf("===||\n");
		}
		else
		    {
			for (col = 0; col < SIZE - 1; col++)
			{
				if (col % SQRT_SIZE == SQRT_SIZE - 1)
					printf("---++");
				else
					printf("---+");
			}
			printf("---||\n");
		}
	}
}

/* Checks if the value is valid and can be set into the matrix.
* The function returns false if the value is already present or
* has been one of the initial values. */
int checkValueInMatrix(int value, int row, int col)
{
	int i, r, c;
	int squareRow;
	int squareCol;
	// checks for initial values
	if (initial[row][col] != 0)
	{
		if (initial[row][col] == value)
			return 1;
		else
			return 0;
	}

	for (i = 0; i < SIZE; i++)
	{
		if (matrix[row][i] == value) return 0;
	}

	for (i = 0; i < SIZE; i++)
	{
		if (matrix[i][col] == value) return 0;
	}

	squareRow = row / SQRT_SIZE;
	squareCol = col / SQRT_SIZE;
	for (r = squareRow * SQRT_SIZE; r < squareRow * SQRT_SIZE + SQRT_SIZE; r++)
	{
		for (c = squareCol * SQRT_SIZE; c < squareCol * SQRT_SIZE + SQRT_SIZE; c++)
		{
			if (matrix[r][c] == value) return 0;
		}
	}

	return 1;
}

/* Set a value in the sudoku matrix if the matrix is empty.
* The method returns false if the matrix contains a fixed number. */
int setValueInMatrix(int value, int row, int col)
{
	if (initial[row][col] == 0)
	{
        matrix[row][col] = value;
		return 1;
	}
	else if (initial[row][col] == value)
		return 1;
	return 0;
}

/* Removes a value in the Sudoku Matrix if it doesn't contain an initial value.
* The method returns false if the matrix contains a fixed number and cannot be
* removed. */
int removeValueFromMatrix(int row, int col)
{
	if (initial[row][col] == 0) {
        matrix[row][col] = 0;
		return 1;
	}
	return 0;
}

/* Returns the value in the matrix */
int getValueFromMatrix(int row, int col)
{
	return matrix[row][col];
}

/* Return true if you've found a valid solution for the Sudoku. Use the
* return value to abort the backtracking algorithm if you've found the
* first solution, otherwise you would search for a possible solution. */
int solve(int row, int col)
{
	if (row == 9)
	{
		return 1;
	}

	for (int i = 1; i < 10; i++)
	{
		if (checkValueInMatrix(i, row, col))
		{
            setValueInMatrix(i, row, col);
            if (col == 8)
            {
                if (solve(row + 1, 0))
                    return 1;
            } else
                {
                if (solve(row, col + 1))
                    return 1;
            }
        }
        removeValueFromMatrix(row, col);
	}
	return 0;
}


