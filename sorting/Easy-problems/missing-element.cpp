#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>v[i];
    }
    int xor1=0;
    int xor2=0;
    for(int i=0;i<n-1;i++){
        xor1=xor1^v[i];
        xor2=xor2^(i+1);
    }
    xor2=xor2^n;
    cout<<"The missing number is:"<<(xor1^xor2)<<endl;

}