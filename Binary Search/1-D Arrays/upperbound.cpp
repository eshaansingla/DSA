#include<bits/stdc++.h>
using namespace std;
int fun(vector<int>&nums,int target,int low,int high){
int ans=high+1;
int mid;
if(low>=high) return -1;
while(low<=high){
mid=low + (high-low)/2;
if(nums[mid]<=target){ 
    low=mid+1;
}
else{
    ans=mid;
    high=mid-1;
}
}
return mid;
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
    int sol=fun(nums,target,0,n-1);
    cout<<sol<<endl;
}