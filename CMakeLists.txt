cmake_minimum_required(VERSION 3.16)
project(sudoku_solver C)

set(CMAKE_C_STANDARD 99)

add_executable(sudoku_solver main.c solver.c reader.c)