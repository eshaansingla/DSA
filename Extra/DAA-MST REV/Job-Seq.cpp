#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> start = {0, 3, 1, 5, 5, 8};
    vector<int> end = {5, 4, 2, 9, 7, 9};
    vector<pair<int, int>> mpp;
    for (int i = 0; i < start.size(); i++)
        mpp.push_back({start[i], end[i]});
    sort(mpp.begin(), mpp.end(), [](auto &a, auto &b)
         { return a.second < b.second; });
    int cnt = 0;
    int free = 0;
    for (auto it : mpp)
    {
        if (it.first > free)
        {
            cnt++;
            free = it.second;
        }
    }
    cout << cnt;
}