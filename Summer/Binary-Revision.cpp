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
void reversed(vector<int> &arr, int m)
{
    int i = m + 1;
    int j = arr.size() - 1;
    while (i <= j)
    {
        swap(arr[i++], arr[j--]);
    }
}
vector<int> merge2sorted(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i++]);
        }
        else
            ans.push_back(arr2[j++]);
    }
    while (i < n)
        ans.push_back(arr1[i++]);
    while (j < m)
        ans.push_back(arr2[j++]);
    return ans;
}
void remove0s(vector<int> &nums)
{
    int nonzeros = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[nonzeros++], nums[i]);
        }
    }
}
void rotateArray(vector<int> &vec, int k)
{
    // 1 2 3 7 9
    // 7 9 1 2 3
    // 3 2 1 7 9
    // 3 2 1 9 7
    // 7 9 1 2 3
    reverse(vec.begin(), vec.begin() + k);
    reverse(vec.begin() + k, vec.end());
    reverse(vec.begin(), vec.end());
}
vector<int> addition(vector<int> &a, vector<int> &b)
{
    vector<int> ans(max(a.size(), b.size()) + 1, 0);
    int i = a.size() - 1;
    int j = b.size() - 1;
    int k = ans.size() - 1;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int temp = a[i--] + b[j--] + carry;
        if (temp >= 10)
        {
            carry = (temp - temp % 10) / 10;
            temp = temp % 10;
        }
        else
            carry = 0;
        ans[k--] = (temp);
    }
    while (i >= 0)
    {
        int temp = a[i--] + carry;
        if (temp >= 10)
        {
            carry = (temp - temp % 10) / 10;
            temp = temp % 10;
        }
        else
            carry = 0;
        ans[k--] = (temp);
    }
    while (j >= 0)
    {
        int temp = b[j--] + carry;
        if (temp >= 10)
        {
            carry = (temp - temp % 10) / 10;
            temp = temp % 10;
        }
        else
            carry = 0;
        ans[k--] = (temp);
    }
    ans[k--] = carry;
    carry = 0;
    i = 0;
    while (i < ans.size() && ans[0] == 0)
    {
        ans.erase(ans.begin());
        i++;
    }
    return ans;
}
int main()
{
    vector<int> vec = {1, 2, 3, 3, 3, 3, 4, 5};
    vector<int> p = {1, 2, 4, 5, 5, 3, 25, 1, 0};
    cout << firstocc(vec, 3) << endl;
    cout << lastocc(vec, 3) << endl;
    cout << lastocc(vec, 3) - firstocc(vec, 3) + 1 << endl;
    cout << p[peak(p)] << endl;
    reversed(vec, 4);
    for (auto it : vec)
        cout << it << " ";
    cout << endl;
    vector<int> v1 = {2, 3, 3, 4, 4, 4, 4, 5, 6, 6, 6, 6, 77};
    vector<int> v2 = {1, 2, 2, 2, 2, 5, 6, 6, 6, 7, 8, 9, 9, 9};
    vector<int> ans = merge2sorted(v1, v2, v1.size(), v2.size());
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    vector<int> arr = {0, 1, 0, 0, 0, 3, 4, 0, 0, 2, 3, 4, 0, 0, 0, 1, 0, 0};
    remove0s(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    vector<int> a = {1, 2, 3, 7, 9};
    rotateArray(a, 3);
    for (auto it : a)
        cout
            << it << " ";
    cout << endl;
    vector<int> add1 = {9, 9, 9};
    vector<int> add2 = {9, 9, 9};
    vector<int> add = addition(add2, add1);
    for (auto it : add)
    {
        cout << it << " ";
    }
    cout << endl;
}