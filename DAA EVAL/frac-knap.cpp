#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> profits = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;
    vector<tuple<int, int, float>> tup;
    for (int i = 0; i < profits.size(); i++)
    {
        tup.push_back({profits[i], weights[i], (float)profits[i] / weights[i]});
    }
    sort(tup.begin(), tup.end(), [](const auto &a, const auto &b)
         { return get<2>(a) > get<2>(b); });
    int profit = 0;
    for (auto it : tup)
    {
        if (W <= 0)
            break;
        if (W - get<1>(it) >= 0)
        {
            W -= get<1>(it);
            profit += get<0>(it);
        }
        else
        {
            profit += get<2>(it) * W;
            W = 0;
        }
    }
    cout << profit;
}