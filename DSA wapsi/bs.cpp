#include <bits/stdc++.h>
using namespace std;
void first_and_last(vector<int> &nums)
{
    int key = 11;
    int low = 0;
    int high = nums.size() - 1;
    int last = -1;
    int first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < key)
        {
            low = mid + 1;
        }
        else if (nums[mid] == key)
        {
            last = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < key)
        {
            low = mid + 1;
        }
        else if (nums[mid] == key)
        {
            first = mid;
            high = mid - 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << first << " " << last << endl;
}
int main()
{
    vector<int> s = {1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 6, 6, 6, 7, 8, 9, 10, 10, 11};
    first_and_last(s);
}