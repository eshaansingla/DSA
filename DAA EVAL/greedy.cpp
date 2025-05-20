#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    int free = 0;
    vector<string> lund_le_gpt;
    vector<tuple<int, int, string>> jobs;
    for (int i = 0; i < start.size(); i++)
    {
        jobs.push_back({end[i], start[i], "J" + to_string(i)});
    }
    sort(jobs.begin(), jobs.end());
    for (auto it : jobs)
    {
        if (get<1>(it) >= free)
        {
            lund_le_gpt.push_back(get<2>(it));
            free = get<0>(it);
        }
    }
    for (auto it : lund_le_gpt)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "TOTAL JOBS DONE:" << lund_le_gpt.size();
}