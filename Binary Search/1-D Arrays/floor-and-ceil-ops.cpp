#include<bits/stdc++.h>
using namespace std;
int flow(vector<int> &nums,int target,int low,int high){
int mid;
int ans=-1;
while(low<=high){
    mid=low + (high-low)/2;
if(nums[mid]<=target){
    ans=nums[mid];
    low=mid+1;
}
else high=mid-1;
}
return ans;
}
int roof(vector<int> &nums,int target,int low,int high){
int mid;
int ans=-1;
while(low<=high){
    mid=low + (high-low)/2;
if(nums[mid]<target){
    low=mid+1;
}
else {
    ans=nums[mid];
    high=mid-1;
}
}
return ans;
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
    cout<<"Closest lower or equal value: "<<flow(nums,target,0,n-1)<<endl;
    cout<<"Closest higher or equal value: "<<roof(nums,target,0,n-1)<<endl;
}