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
    for(int j=1;j<n;j++){
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]) swap(arr[i],arr[i-1]);
    }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}