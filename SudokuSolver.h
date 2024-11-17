#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <iostream>
using namespace std;

bool Solve(int grid[9][9], int param);
void Print(int grid[9][9]);
bool Valid(int grid[9][9]);

#endif
