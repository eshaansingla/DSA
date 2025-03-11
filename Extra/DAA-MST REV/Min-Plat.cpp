#include <bits/stdc++.h>
using namespace std;
int MinPlats(vector<int> &a, vector<int> &d)
{
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    int min = 1;
    int tol = 1;
    int i = 1;
    int j = 0;
    while (i < a.size() && j < d.size())
    {
        if (a[i] <= d[j])
        {
            tol++;
            i++;
        }
        else
        {
            tol--;
            j++;
        }
        min = max(tol, min);
    }
    return min;
}
int main()
{
    vector<int> arrival = {900, 945, 955, 1100, 1500, 1800};
    vector<int> departure = {920, 1200, 1130, 1150, 1900, 2000};
    cout << MinPlats(arrival, departure);
}