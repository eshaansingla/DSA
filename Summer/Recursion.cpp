#include <bits/stdc++.h>
using namespace std;
int climbStairs(int n)
{
    if (n == 1 || n == 2)
        return n;
    return climbStairs(n - 1) + climbStairs(n - 2);
}
int sumdat(int i, vector<int> &nums)
{
    if (i == 0)
        return nums[i];
    return nums[i] + sumdat(i - 1, nums);
}
int binarySearch(int low, int high, vector<int> &nums, int search)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (nums[mid] == search)
        return mid;
    else if (nums[mid] > search)
        return binarySearch(low, mid - 1, nums, search);
    else
        return binarySearch(mid + 1, high, nums, search);
}
void revString(int i, int j, string &a)
{
    if (i > j)
        return;
    swap(a[i], a[j]);
    revString(i + 1, j - 1, a);
}
bool palindromeString(int i, string a)
{
    if (i == a.size() / 2)
        return true;
    if (a[i] != a[a.size() - i - 1])
        return false;
    return palindromeString(i + 1, a);
}
void merge(int low, int mid, int high, vector<int> &nums)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left++]);
        }
        else
        {
            temp.push_back(nums[right++]);
        }
    }
    while (left <= mid)
        temp.push_back(nums[left++]);
    while (right <= high)
        temp.push_back(nums[right++]);
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}
void mergeSort(int low, int high, vector<int> &nums)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(low, mid, nums);
    mergeSort(mid + 1, high, nums);
    merge(low, mid, high, nums);
}
void Subsets(vector<int> &nums, int i, vector<vector<int>> &sol, vector<int> temp)
{
    if (i == nums.size())
    {
        sol.emplace_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    Subsets(nums, i + 1, sol, temp);
    temp.pop_back();
    Subsets(nums, i + 1, sol, temp);
}
void solver(unordered_map<char, string> &digitToLetters, int ind, string temp, vector<string> &ans, string digits)
{
    if (ind == digits.size())
    {
        ans.push_back(temp);
        return;
    }
    string word = digitToLetters[digits[ind]];
    for (auto it : word)
    {
        solver(digitToLetters, ind + 1, temp + it, ans, digits);
    }
}
vector<string> PhoneNo(string digits)
{
    vector<string> ans;
    unordered_map<char, string> digitToLetters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    solver(digitToLetters, 0, "", ans, digits);
    return ans;
}
int main()
{
    cout << climbStairs(3) << endl;
    vector<int> nums = {3, 2, 5, 1, 6};
    cout << sumdat(nums.size() - 1, nums) << endl;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 8, 9, 9, 9, 11};
    cout << binarySearch(0, arr.size() - 1, arr, 11) << endl;
    string s = "Eshaan Singla";
    cout << s << endl;
    revString(0, s.size() - 1, s);
    cout << s << endl;
    cout << palindromeString(0, s) << endl;
    string b = "NAMAN";
    cout << palindromeString(0, b) << endl;
    vector<int> arr1 = {1, 2, 3, 4, 1, 23, 4, 5};
    mergeSort(0, arr1.size() - 1, arr1);
    for (auto it : arr1)
        cout << it << " ";
    cout << endl;
    vector<int> a = {1, 2, 3};
    vector<int> vec = {};
    vector<vector<int>> ans;
    Subsets(a, 0, ans, vec);
    for (auto it : ans)
    {
        cout << "{";
        for (auto it1 : it)
            cout << it1 << ",";
        cout << "}";
    }
    cout << endl;
    string digits = "374226";
    vector<string> msg = PhoneNo(digits);
    for (auto it : msg)
    {
        cout << it << endl;
    }
    cout << endl;
}