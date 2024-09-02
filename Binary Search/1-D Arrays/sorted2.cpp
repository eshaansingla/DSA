#include<bits/stdc++.h>
using namespace std;
bool bs(vector<int>& nums, int target,int low,int high){
        if(low>high) return false;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[high] && nums[mid]==nums[low]){
                high--;
                low++;
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>=target) high=mid-1;
                else low=mid+1;
            }
            else {
                if(nums[mid]<=target && nums[high]>=target) low=mid+1;
                else high=mid-1;
            }
        }
        return false;
    }
int main(){
    //brute
    /*for(int i=0;i<n;i++) if(nums[i]==target){
        cout<<i<<endl;
        break;
    }
    */
   //optimal
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