#include <bits/stdc++.h>
using namespace std;
int firstocc(vector<int> &v, int s)
{
    int low = 0;
    int high = v.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == s)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (v[mid] > s)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int lastocc(vector<int> &v, int s)
{
    int low = 0;
    int high = v.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == s)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (v[mid] > s)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int peak(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid >= 1 && mid + 1 < nums.size() && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        else if (nums[mid] >= nums[mid - 1])
        {
            low = mid + 1;
        }
        else if (nums[mid] >= nums[mid + 1])
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> vec = {1, 2, 3, 3, 3, 3, 4, 5};
    vector<int> p = {1, 2, 4, 5, 5, 3, 25, 1, 0};
    cout << firstocc(vec, 3) << endl;
    cout << lastocc(vec, 3) << endl;
    cout << lastocc(vec, 3) - firstocc(vec, 3) + 1 << endl;
    cout << p[peak(p)] << endl;
}