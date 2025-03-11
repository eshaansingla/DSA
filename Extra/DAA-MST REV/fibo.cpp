#include <bits/stdc++.h>
using namespace std;
int fibo(int n, vector<int> &dp)
{
    if (n == 0 or n == 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}
int main()
{
    int n = 11;
    vector<int> v(n + 1, -1);
    cout << fibo(n, v) << endl; // 0 1 1 2 3 5 8 13 21 34 55
    int a = 0;
    int b = 1;
    for (int i = 0; i <= n; i++)
    {
        cout << a << " ";
        int temp = a + b;
        a = b;
        b = temp;
    }
}