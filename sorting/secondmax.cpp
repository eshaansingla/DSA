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
    int max=0;
    for(int i=0;i<n;i++){
        if(max<arr[i]) max=arr[i];
    }
    int max2;
    for(int i=0;i<n;i++){
        if(max2<arr[i] && arr[i]!=max) max2=arr[i];
    }
    cout<<max2;
}