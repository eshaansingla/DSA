#include <bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int> arr, int search, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > search)
        {
            high = mid - 1;
        }
        else if (arr[mid] == search)
            return mid;
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
// int BinarySearch(vector<int> arr, int search, int low, int high)
// {
//     if (low > high)
//         return -1;
//     int mid = low + (high - low) / 2;
//     if (arr[mid] > search)
//     {
//         return BinarySearch(arr, search, low, mid - 1);
//     }
//     else if (arr[mid] == search)
//         return mid;
//     else
//     {
//         return BinarySearch(arr, search, mid + 1, high);
//     }
// }
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
        int x;
        cout << "Enter the element to search: ";
        cin >> x;
        cout << "Index: " << BinarySearch(arr, x, 0, arr.size() - 1) << endl;
    }
}