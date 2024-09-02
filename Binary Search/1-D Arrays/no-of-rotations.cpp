#include<bits/stdc++.h>
using namespace std;
int noofrot(vector<int>nums,int low,int high){
if(low>high) return -1;
int ans=0;
while(low<=high){
    int mini=INT_MAX;
    int mid=low + (high-low)/2;
    if(nums[low]<=nums[mid]){
        ans=low;
        mini=min(nums[low],mini);
        low=mid+1;
    }
    else{
        ans=mid;
        mini=min(nums[mid],mini);
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
    cout<<noofrot(nums,0,n-1)<<endl;
}