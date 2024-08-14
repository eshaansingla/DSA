#include <bits/stdc++.h>
using namespace std;
vector<int> reverseArray(int a[], int n) {
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        b[n - i - 1] = a[i];
    }
    return b;
}
string reverseArray(string str) {
    reverse(str.begin(), str.end());
    return str;
}

int main() {
    int arr[] = {1, 5, 9, 2, 3, 4, 5, 6, 8, 7, 9, 5};
    int m = sizeof(arr) / sizeof(arr[0]);
    
    vector<int> c = reverseArray(arr, m);
    
    for(auto it : c) {
        cout << it << endl;

     string arr="Eshaan Singla";
    string ch = reverseArray(arr);
    cout<<ch<<endl;
    return 0;
    }
    
    return 0;
}
