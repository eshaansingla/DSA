#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>arr[i];
    }
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1=xor1^arr[i];
    }
    cout<<xor1<<endl;
}