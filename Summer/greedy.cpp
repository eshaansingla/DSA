#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5, 9, 11};
    vector<int> end = {2, 4, 6, 7, 9, 9, 12, 13};
    vector<pair<int, int>> p;
    for (int i = 0; i < start.size(); i++)
    {
        p.push_back({end[i], start[i]});
    }
    sort(p.begin(), p.end(), [](const auto &a, const auto &b)
         { return a.first < b.first; });
    int free = 0;
    int ans = 0;
    for (auto it : p)
    {
        if (free <= it.second)
        {
            ans++;
            free = it.first;
        }
    }
    cout << ans << endl;
    int n = 4;
    int k = 2;
    vector<int> candy = {3, 2, 1, 4};
    sort(candy.begin(), candy.end());
    int i = 0;
    int j = candy.size() - 1;
    int price = 0;
    while (i <= j)
    {
        price += candy[i++];
        for (int l = 0; l < k; l++)
        {
            j--;
        }
    }
    i = 0;
    j = candy.size() - 1;
    int price2 = 0;
    while (i <= j)
    {
        price2 += candy[j--];
        for (int l = 0; l < k; l++)
        {
            i++;
        }
    }
    cout << price << endl;
    cout << price2 << endl;
    int M = 2, N = 16, S = 10;
    int days = 0;
    int food = 0;
    int sun = S / 7;
    if (S * M % N == 0)
    {
        days = S * M / N;
    }
    else
    {
        days = S * M / N + 1;
    }
    if (days <= S - sun || 7 * M < 6 * N)
        cout << days << endl;
    else
        cout << -1 << endl;
    string inp = "i.like.this.program.very.much";
    string s = "";
    string temp = "";
    bool first = 1;
    for (int i = inp.length() - 1; i >= 0; i--)
    {
        if (inp[i] == '.')
        {
            if (!first)
            {
                temp += inp[i];
            }
            else
                first = 0;
            reverse(temp.begin(), temp.end());
            s += temp;
            temp = "";
        }
        else
        {
            temp += inp[i];
        }
    }
    reverse(temp.begin(), temp.end());
    s += '.';
    s += temp;
    cout << s << endl;
}