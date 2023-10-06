// Create a C++ code to check the winner for TIC TAC TOE GAME
// +1 if agent wins (win for 1)
// 0 in case of tie
// -1 if agent loses (win for 0)

#include <iostream>
using namespace std;
const int N = 3;

int check_winner(int board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += board[i][j];
        }
        if (sum == 3)
            return 1; 
        if (sum == -3)
            return -1; 
    }
    for (int j = 0; j < 3; j++)
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += board[i][j];
        }
        if (sum == 3)
            return 1; 
        if (sum == -3)
            return -1; 
    }
    int sum1 = board[0][0] + board[1][1] + board[2][2];
    int sum2 = board[0][2] + board[1][1] + board[2][0];

    if (sum1 == 3 || sum2 == 3)
        return 1; 
    if (sum1 == -3 || sum2 == -3)
        return -1; 

    bool empty = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
                empty = true;
        }
    }

    if (!empty)
        return 0; 

    return -2;
}

int main()
{
    int board[N][N];
    cout<<"Enter the board"<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>board[i][j];
        }
    }

    int result = check_winner(board);

    if (result == 1)
        cout << "Agent wins" << endl;
    else if (result == -1)
        cout << "Agent loses" << endl;
    else if (result == 0)
        cout << "Tie" << endl;
    else
        cout << "No result yet" << endl;

    return 0;
}