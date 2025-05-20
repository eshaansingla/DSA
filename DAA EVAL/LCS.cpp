#include <bits/stdc++.h>
using namespace std;
int comp(string &s1, string &s2, int i, int j)
{
    if (i >= s1.size() || j >= s2.size())
    {
        return 0;
    }
    if (s1[i] == s2[j])
    {
        return 1 + comp(s1, s2, i + 1, j + 1);
    }
    return max(comp(s1, s2, i + 1, j), comp(s1, s2, i, j + 1));
}
int main()
{
    string s1 = "AGGTAB", s2 = "GXTXAYB";
    // int ans = comp(s1, s2, 0, 0);
    // cout << ans << endl;
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i] == s2[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    string ans = "";
    int i = s1.size();
    int j = s2.size();
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}