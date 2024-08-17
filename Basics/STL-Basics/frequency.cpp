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
    int max=0;
    int hif,lof;
    for(int i=0;i<n;i++){
        if(mpp[arr[i]]>max) {
            max=mpp[arr[i]];
            hif=arr[i];
    }
    }
    for(int i=0;i<n;i++){
        if(mpp[arr[i]]<max) {
            max=mpp[arr[i]];
            lof=arr[i];
    }
    }
    cout<<hif<<" "<<lof<<endl;
}