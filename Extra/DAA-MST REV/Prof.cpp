#include <bits/stdc++.h>
using namespace std;
int Prof(vector<int> &p, vector<int> &d)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < p.size(); i++)
    {
        v.push_back({p[i], d[i]});
    }
    sort(v.begin(), v.end(), [](const auto &a, const auto &b)
         {if(a.second==b.second) return a.first > b.first;return a.second<b.second; });
    int ans = 0;
    int free = 0;
    for (auto it : v)
    {
        if (it.second > free)
        {
            free = it.second;
            ans += it.first;
        }
    }
    return ans;
}
int main()
{
    vector<int> profit = {50, 15, 10, 25};
    vector<int> deadline = {2, 1, 2, 1};
    cout << Prof(profit, deadline);
}