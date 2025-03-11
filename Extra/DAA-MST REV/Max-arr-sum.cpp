#include <bits/stdc++.h>
using namespace std;
int giveans(int low, int mid, int high, vector<int> &sol)
{
    int sum = 0;
    int lss = INT_MIN;
    for (int i = mid; i >= low; i--)
    {
        sum += sol[i];
        lss = max(lss, sum);
    }
    sum = 0;
    int rss = INT_MIN;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += sol[i];
        rss = max(rss, sum);
    }
    return lss + rss;
}
int solve(int low, int high, vector<int> &sol)
{
    if (low == high)
        return sol[low];
    int mid = low + (high - low) / 2;
    int lss = solve(low, mid, sol);
    int rss = solve(mid + 1, high, sol);
    int css = giveans(low, mid, high, sol);
    return max(lss, max(rss, css));
}
int main()
{
    vector<int> s = {-1, 2, 2, 3, -10, 120, -80, 100, -122};
    int local = 0;
    int global = INT_MIN;
    for (int i = 0; i < s.size(); i++)
    {
        local = max(s[i], local + s[i]);
        global = max(global, local);
    }
    int sum = 0;
    int t = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sum = 0;
        for (int j = i + 1; j < s.size(); j++)
        {
            sum += s[j];
            t = max(t, sum);
        }
    }
    cout << t << endl;
    cout << solve(0, s.size() - 1, s) << endl;
    cout << global << endl;
}
