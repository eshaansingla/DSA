#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &v, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp(v.size(), 0);
    int i = 0;
    while (left <= mid && right <= high)
    {
        if (v[left] < v[right])
        {
            temp[i++] = v[left++];
        }
        else
            temp[i++] = v[right++];
    }
    while (left <= mid)
    {
        temp[i++] = v[left++];
    }
    while (right <= high)
    {
        temp[i++] = v[right++];
    }
    for (int j = low; j <= high; j++)
    {
        v[j] = temp[j - low];
    }
}
void mergeSort(vector<int> &v, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}
int main()
{
    int cases;
    cout << "Enter cases: ";
    cin >> cases;
    while (cases--)
    {
        int size;
        cout << "Enter size: ";
        cin >> size;
        vector<int> arr(size);
        cout << "Enter array elements: ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        cout << "Sorted Array: \n";
        mergeSort(arr, 0, arr.size() - 1);
        for (auto it : arr)
            cout << it << " ";
        cout << endl;
    }
}