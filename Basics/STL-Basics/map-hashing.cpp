#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int>mpp;
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element:";
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    int a;
    while(true){
        cout<<"Enter the number to be found:";
        cin>>a;
        cout<<mpp[a]<<endl;
    }
}