#include<bits/stdc++.h>
using namespace std;
//brute
/*vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int k;
        for(int i=0;i<nums.size();i++){
            if(target==nums[i]) l++;
        }
        for(int i=0;i<nums.size();i++){
            if(target==nums[i]){
                k=i;
                break;
            }
        }
        if(l==0) return {-1,-1};
         return {k,k+l-1};
    }*/
   //better
   /*vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int u = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(u>l)return {l,u-1};
        else return {-1,-1};
   }*/

   //optimal 
   int left(vector<int>& nums, int target,int low,int high){
    int mid;
    int ans=-1;
    while(low<=high){
        mid=low+ (high-low)/2;
        if(nums[mid]==target){
            ans=mid;
            high=mid-1;
        }
        else if(nums[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return ans;
   }
   int right(vector<int>& nums, int target,int low,int high){
    int mid;
    int ans=-1;
    while(low<=high){
        mid=low+ (high-low)/2;
        if(nums[mid]==target){
            ans=mid;
            low=mid+1;
        }
        else if(nums[mid]<target) low=mid+1;
        else high=mid-1;
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
    //vector<int>sol=searchRange(nums,target);
    //for(auto it:sol) cout<<it<<" ";
    int l=left(nums,target,0,n-1);
    if(l==-1) cout<<-1<<","<<-1;
    int u=right(nums,target,0,n-1);
    cout<<l<<","<<u;
    }