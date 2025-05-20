#include <bits/stdc++.h>
using namespace std;
int JobsProfit(vector<tuple<int, int, int>> jobs)
{
    int maxprofit = 0;
    int maxdeadline = 0;
    for (auto it : jobs)
    {
        if (get<1>(it) > maxdeadline)
            maxdeadline = get<1>(it);
    }
    vector<int> slot(maxdeadline + 1, -1);
    for (auto it : jobs)
    {
        for (int t = min(get<1>(it), maxdeadline); t > 0; t--)
        {
            if (slot[t] == -1)
            {
                slot[t] = get<0>(it);
                maxprofit += get<2>(it);
                break;
            }
        }
    }
    return maxprofit;
}
int main()
{
    vector<int> id = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> deadline = {4, 5, 6, 6, 4, 2, 2, 2};
    vector<int> profit = {20, 60, 70, 65, 25, 80, 10, 22};
    vector<tuple<int, int, int>> jobs;
    for (int i = 0; i < id.size(); i++)
    {
        jobs.emplace_back(id[i], deadline[i], profit[i]);
    }
    sort(jobs.begin(), jobs.end(), [](const auto a, const auto b)
         {
            if(get<2>(a) != get<2>(b)) return  get<2>(a) > get<2>(b);
            else return  get<1>(a) < get<1>(b); });
    for (const auto &job : jobs)
    {
        cout << "ID: " << get<0>(job)
             << ", Deadline: " << get<1>(job)
             << ", Profit: " << get<2>(job) << endl;
    }
    cout << JobsProfit(jobs) << endl;
}