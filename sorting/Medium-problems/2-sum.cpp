#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    int sum;
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>arr[i];
    }
    cout<<"Enter sum:";
    cin>>sum;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        int target=sum-arr[i];
        if(mpp.find(target)!=mpp.end()){
            cout<<"Indexes:"<<mpp[target]<<","<<i<<endl;
             cout<<"Numbers:"<<target<<","<<sum-target<<endl;
        }
       mpp[arr[i]]=i;
    }
    }