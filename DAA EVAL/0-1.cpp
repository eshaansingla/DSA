#include <bits/stdc++.h>
using namespace std;
int knapsack(int i, vector<int> &p, vector<int> &w, int W, int n, int val)
{
    if (i >= n)
        return val;
    if (W - w[i] < 0)
    {
        return knapsack(i + 1, p, w, W, n, val);
    }
    return max(knapsack(i + 1, p, w, W, n, val), knapsack(i + 1, p, w, W - w[i], n, val + p[i]));
}
int main()
{
    int W = 7;
    vector<int> profit = {5, 3, 8, 6};
    vector<int> weight = {2, 3, 4, 5};
    cout << knapsack(0, profit, weight, W, profit.size(), 0);
    vector<vector<int>> dp(profit.size() + 1, vector<int>(W + 1, 0));
    for (int i = 1; i < profit.size() + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (j - weight[i - 1] < 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(profit[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
        }
    }
    cout << dp[profit.size()][W] << endl;
}