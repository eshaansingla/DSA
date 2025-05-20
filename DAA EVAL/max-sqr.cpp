#include <bits/stdc++.h>
using namespace std;
int recc(int i, int j, vector<vector<int>> &p, int row, int col, int &maxi)
{
    if (i >= row || j >= col)
    {
        return 0;
    }
    if (p[i][j] == 1)
    {
        int right = recc(i, j + 1, p, row, col, maxi);
        int diagonal = recc(i + 1, j + 1, p, row, col, maxi);
        int down = recc(i + 1, j, p, row, col, maxi);
        int ans = 1 + min({right, diagonal, down});
        maxi = max(maxi, ans);
        return ans;
    }
    else
        return 0;
}
int main()
{
    vector<vector<int>> v = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}};
    int maxi = 0;
    int row = v.size();
    int col = v[0].size();
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         recc(i, j, v, row, col, maxi);
    //     }
    // }
    // cout << maxi;
    vector<vector<int>> dp(v.size() + 1, vector<int>(v.size() + 1, 0));
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            if (v[i][j] == 1)
            {
                int right = dp[i][j + 1];
                int diag = dp[i + 1][j + 1];
                int bottom = dp[i + 1][j];
                dp[i][j] = 1 + min({right, diag, bottom});
                maxi = max(dp[i][j], maxi);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << maxi << endl;
}