#include<bits/stdc++.h>
using namespace std;
//recursion
int func(vector<int>& nums, int target,int low,int high){
        int mid=(low+high)/2;
        if(low>high) return -1;
        else if(target==nums[mid]) return mid;
        else if(nums[mid]>target) return func(nums,target,low,mid-1);
        return func(nums,target,mid+1,high);
    }
int main(){
    vector<int>nums(5);
    int target;
     int n=nums.size();
     for(int i=0;i<n;i++){
        cout<<"Enter a number";
        cin>>nums[i];
     }
     cout<<"Enter the target:";
     cin>>target;
        int low=0;
        int high=n-1;
    cout<< func(nums,target,low,high);
        /*
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) {
                cout<< mid;
                break;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout<< -1;*/
    }
