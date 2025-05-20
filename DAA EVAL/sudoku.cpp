#include <bits/stdc++.h>
using namespace std;
bool valid(int i, int j, int k, vector<vector<int>> &board)
{
    for (int n = 0; n < 9; n++)
    {
        if (board[i][n] == k)
            return false;
        if (board[n][j] == k)
            return false;
        if (board[(i / 3) * 3 + n / 3][(j / 3) * 3 + n % 3] == k)
            return false;
    }
    return true;
}
bool solver(vector<vector<int>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (valid(i, j, k, board))
                    {
                        board[i][j] = k;
                        if (solver(board))
                            return true;
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> board =
        {{5, 3, 0, 0, 7, 0, 0, 0, 0},
         {6, 0, 0, 1, 9, 5, 0, 0, 0},
         {0, 9, 8, 0, 0, 0, 0, 6, 0},
         {8, 0, 0, 0, 6, 0, 0, 0, 3},
         {4, 0, 0, 8, 0, 3, 0, 0, 1},
         {7, 0, 0, 0, 2, 0, 0, 0, 6},
         {0, 6, 0, 0, 0, 0, 2, 8, 0},
         {0, 0, 0, 4, 1, 9, 0, 0, 5},
         {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    solver(board);
    for (auto it : board)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
}