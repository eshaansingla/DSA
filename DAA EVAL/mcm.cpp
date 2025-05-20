#include <bits/stdc++.h>
using namespace std;
void bracketss(int i, int j, vector<vector<int>> &bracks, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << '(';
    bracketss(i, bracks[i][j], bracks, name);
    bracketss(bracks[i][j] + 1, j, bracks, name);
    cout << ')';
}
void mcm(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> brackets(n, vector<int>(n, 0));
    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    brackets[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    bracketss(1, n - 1, brackets, name);
    cout << endl;
    cout << dp[1][n - 1] << endl;
}
int main()
{
    vector<int> arr = {2, 1, 3, 4, 5, 6, 4}; // Example input
    mcm(arr);
    return 0;
}