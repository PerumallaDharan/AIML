// Implement 8 Queens program using backtracking

#include <iostream>
using namespace std;

int board[8][8] = {0};

bool isSafe(int row, int col)
{
    // Check for row
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
            return false;
    }

    // Check for upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check for lower left diagonal
    for (int i = row, j = col; i < 8 && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(int col)
{
    if (col >= 8)
        return true;

    for (int i = 0; i < 8; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1;

            if (solve(col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    if (solve(0))
    {
        cout << "Solution exists\n";

        for (int i = 0; i < 8; i++)
        {
            cout << endl;
            for (int j = 0; j < 8; j++)
            {
                cout << board[i][j] << " ";
            }
        }
    }
    else
    {
        cout << "Solution does not exist\n";
    }

    return 0;
}
