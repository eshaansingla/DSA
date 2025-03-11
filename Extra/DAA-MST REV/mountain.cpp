#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> start = {0, 1, 1, 2, 3, 4, 5, 2};
    int low = 0;
    int high = start.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (start[mid] > start[mid - 1] && start[mid] > start[mid + 1] && mid >= 1)
        {
            cout << start[mid] << endl;
            break;
        }
        if (start[mid] < start[mid + 1])
            low = mid + 1;
        else
        {
            high = mid - 1;
        }
    }
}