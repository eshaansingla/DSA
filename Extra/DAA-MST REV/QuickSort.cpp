#include <bits/stdc++.h>
using namespace std;
void quickSort(vector<int> &arr, int low, int high)
{
}
int main()
{
    vector<int> arr = {1, 2, 3, 42, 12, 0, 313, 0, 13};
    quickSort(arr, 0, arr.size() - 1);
    for (auto it : arr)
        cout << it << " ";
    return 0;
}
