#include <bits/stdc++.h>
using namespace std;
int part(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;
    int j = high - 1;
    while (i <= j)
    {
        while (i < high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot && j >= low)
            j--;
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[high]);
    return i;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pindex = part(arr, low, high);
        quickSort(arr, low, pindex - 1);
        quickSort(arr, pindex + 1, high);
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 42, 12, 0, 313, 0, 13};
    quickSort(arr, 0, arr.size() - 1);
    for (auto it : arr)
        cout << it << " ";
}
