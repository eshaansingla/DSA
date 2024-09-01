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

   //optimal mkae fxns for lower and upper bound separately and calculate.

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
    }