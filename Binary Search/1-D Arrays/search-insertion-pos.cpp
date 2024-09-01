#include<bits/stdc++.h>
using namespace std;
int bs(vector<int>&nums,int target,int low,int high){
    int mid;
    while(low<=high){
        mid=low + (high-low)/2;
        if(nums[mid]<target) low=mid+1;
        else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>nums(n);
    int target;
    for(int i=0;i<n;i++){
       cout<<"Enter a number:";
       cin>>nums[i];
    }
    cout<<"Enter the target:";
    cin>>target;
    cout<<bs(nums,target,0,n-1)<<endl;
}