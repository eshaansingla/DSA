#include <bits/stdc++.h>
using namespace std;
bool okay(int row, int col, vector<string> &board, int n)
{
    int r = row;
    int c = col;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    row = r;
    col = c;
    while (col >= 0 && row < n)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
        row++;
    }
    row = r;
    col = c;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
        row--;
    }
    row = r;
    col = c;
    return true;
}
void solver(vector<vector<string>> &solutions, int col, int n, vector<string> &board)
{
    if (col == n)
    {
        solutions.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (okay(i, col, board, n))
        {
            board[i][col] = 'Q';
            solver(solutions, col + 1, n, board);
            board[i][col] = '.';
        }
    }
}
int main()
{
    int n = 4;
    vector<string> board;
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board.emplace_back(s);
    }
    vector<vector<string>> v;
    solver(v, 0, n, board);
    for (auto it : v)
    {
        for (auto it1 : it)
        {
            cout << it1 << endl;
        }
        cout << endl;
    }
}