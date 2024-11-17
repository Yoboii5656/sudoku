#include "SudokuSolver.h"

bool Solve(int grid[9][9], int index)
{
    // Function logic remains the same
    static int it = 0;

    if (index > 80)
        return true;

    if (((int *)grid)[index])
        return Solve(grid, index + 1);

    for (int digit = 1; digit < 10; digit++)
    {
        static int row, column, blockStart;

        row = index / 9;
        column = index % 9;
        blockStart = row / 3 * 27 + column / 3 * 3;

        int i;
        for (i = 0; i < 9; i++)
        {
            if (grid[row][i] == digit || grid[i][column] == digit || ((int *)grid)[blockStart + i / 3 * 9 + i % 3] == digit)
                break;
        }

        if (i == 9)
            ((int *)grid)[index] = digit;
        else
            continue;

        if (Solve(grid, index + 1))
            return true;
        else
            ((int *)grid)[index] = 0;
    }

    return false;
}

void Print(int grid[9][9])
{
    cout << "+-----------------------+\n";

    for (int i = 0; i < 81; i++)
    {
        if (!(i % 3))
            cout << "| ";

        if (!(i % 9) && i)
        {
            if (!(i % 27))
                cout << "\n|-------+-------+-------|\n| ";
            else
                cout << "\n| ";
        }

        cout << ((int *)grid)[i] << ' ';
    }

    cout << "|\n+-----------------------+\n";
    cout.flush();
}

bool Valid(int grid[9][9])
{
    int *grid1d = (int *)grid;
    int row, column, blockStart;

    for (int i = 0; i < 81; i++)
    {
        if (grid1d[i] == 0)
            continue;

        row = i / 9;
        column = i % 9;
        blockStart = row / 3 * 27 + column / 3 * 3;

        for (int j = 0; j < 9; j++)
        {
            if ((grid1d[i] == *(grid1d + row * 9 + j) && grid1d + i != grid1d + row * 9 + j) ||
                (grid1d[i] == *(grid1d + j * 9 + column) && grid1d + i != grid1d + j * 9 + column) ||
                (grid1d[i] == *(grid1d + blockStart + j / 3 * 9 + j % 3) && grid1d + i != grid1d + blockStart + j / 3 * 9 + j % 3))
                return false;
        }
    }

    return true;
}
