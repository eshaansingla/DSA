#include <bits/stdc++.h>
using namespace std;
bool powerof2(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}
bool odd(int n)
{
    if (n & 1)
        return true;
    return false;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    for (auto it : v)
    {
        if (odd(it))
            cout << it << " is odd." << endl;
        else
            cout << "even" << endl;
    }
    // 3*4=12
    cout << (3 << 2) << endl; // x<<k * 2^k
    // 16/2=8
    cout << (16 >> 1) << endl; // x>>k / 2^k
    // x & ((1<<k)-1) => x % 2^k
    int x = 2;
    int y = 5;
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    cout << x << " " << y << endl;
}