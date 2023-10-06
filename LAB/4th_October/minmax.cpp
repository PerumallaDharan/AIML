#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int BOARD_SIZE = 3;
const char EMPTY = '-';
const char PLAYER_1 = 'X';
const char PLAYER_0 = 'O';

vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY));

bool checkWin(char player)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }
    for (int j = 0; j < BOARD_SIZE; ++j)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

bool checkTie()
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                return false;
            }
        }
    }
    return true;
}

int evaluate()
{
    if (checkWin(PLAYER_1))
    {
        return 1;
    }
    else if (checkWin(PLAYER_0))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int minimax(char player)
{
    int score = evaluate();

    if (score != 0)
    {
        return score;
    }

    int bestScore = (player == PLAYER_1) ? -1000 : 1000;

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = player;
                int currentScore = minimax((player == PLAYER_1) ? PLAYER_0 : PLAYER_1);
                board[i][j] = EMPTY;
                if (player == PLAYER_1)
                {
                    bestScore = max(bestScore, currentScore);
                }
                else
                {
                    bestScore = min(bestScore, currentScore);
                }
            }
        }
    }

    return bestScore;
}

void getBestMove(int &row, int &col)
{
    int bestScore = -1000;
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = PLAYER_0;
                int moveScore = minimax(PLAYER_1);
                board[i][j] = EMPTY;
                if (moveScore > bestScore)
                {
                    bestScore = moveScore;
                    row = i;
                    col = j;
                }
            }
        }
    }
}

void displayBoard()
{

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
int determineOutcome()
{
    if (checkWin(PLAYER_1))
    {             
        return 1; 
    }
    else if (checkWin(PLAYER_0))
    {             
        return 0; 
    }
    else if (checkTie())
    {
        return -1; 
    }
    else
    {
        return -2; 
    }
}

int main()
{
    displayBoard();
    cout << endl;

    int currentPlayer = 0; 

    while (true)
    {
        int row, col;
        if (currentPlayer == 0)
        {
            getBestMove(row, col);
        }
        else
        {
            cout << "Player 1, enter your move (1-9): ";
            int move;
            cin >> move;

            if (move < 1 || move > 9)
            {
                cout << "Invalid move! Try again." << endl;
                continue;
            }

            row = (move - 1) / BOARD_SIZE;
            col = (move - 1) % BOARD_SIZE;

            if (board[row][col] != EMPTY)
            {
                cout << "Invalid move! The cell is already occupied. Try again." << endl;
                continue;
            }
        }

        board[row][col] = (currentPlayer == 0 ? PLAYER_0 : PLAYER_1);
        displayBoard();

        int outcome = determineOutcome();
        if (outcome == 1)
        {
            cout << "Player 1 wins! (1)" << endl;
            break;
        }
        else if (outcome == 0)
        {
            cout << "Player 0 wins! (-1)" << endl;
            break;
        }
        else if (outcome == -1)
        {
            cout << "It's a tie! (0)" << endl;
            break;
        }

        currentPlayer = 1 - currentPlayer;
    }

    return 0;
}