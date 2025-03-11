#include <bits/stdc++.h>
using namespace std;
int knapsack(int i, vector<int> &weights, vector<int> &values, int W, vector<vector<int>> &dp)
{
    if (i < 0 || W == 0)
        return 0;
    if (W - weights[i] < 0)
        return dp[i][W] = knapsack(i - 1, weights, values, W, dp);
    if (dp[i][W] != -1)
        return dp[i][W];
    dp[i][W] = max(knapsack(i - 1, weights, values, W, dp), values[i] + knapsack(i - 1, weights, values, W - weights[i], dp));
}
int main()
{
    int n = 4, W = 8;
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << knapsack(n - 1, weights, values, W, dp) << endl;
    vector<int> v(W + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = W; j >= weights[i]; j--)
        {
            v[j] = max(v[j], values[i] + v[j - weights[i]]);
        }
    }
    cout << v[W] << endl;
}