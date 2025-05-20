#include <bits/stdc++.h>
using namespace std;
vector<int> converter(vector<string> nums)
{
    vector<int> sol;
    int hours = 0;
    int mins = 0;
    bool colon = 0;
    for (auto it1 : nums)
    {
        for (auto it : it1)
        {
            if (it == ':')
            {
                colon = 1;
                continue;
            }
            if (!colon)
            {
                hours = hours * 10 + (it - '0');
            }
            else
            {
                mins = mins * 10 + (it - '0');
            }
        }
        sol.emplace_back(hours * 60 + mins);
        hours = 0;
        mins = 0;
        colon = 0;
    }
    return sol;
}
int main()
{
    vector<string> arr = {"9:00", "9:40", "9:50", "11:00", "15:00", "18:00"};
    vector<string> dep = {"9:10", "12:00", "11:20", "11:30", "19:00", "20:00"};
    vector<int> arrtime = converter(arr);
    vector<int> deptime = converter(dep);
    for (auto it : arrtime)
    {
        cout << it << " ";
    }
    cout << endl;
    for (auto it : deptime)
    {
        cout << it << " ";
    }
    int i = 0, j = 0;
    int minplats = 1;
    sort(arrtime.begin(), arrtime.end());
    sort(deptime.begin(), deptime.end());
    int plats = 1;
    while (i < arrtime.size() && j < deptime.size())
    {
        if (arrtime[i] > deptime[j])
        {
            plats--;
            j++;
        }
        else
        {
            plats++;
            i++;
            minplats = max(plats, minplats);
        }
    }
    cout << endl;
    if (minplats == 0)
        minplats++;
    cout << minplats << endl;
}