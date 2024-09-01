#include<bits/stdc++.h>
using namespace std;
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
        cout<< -1;
    }
