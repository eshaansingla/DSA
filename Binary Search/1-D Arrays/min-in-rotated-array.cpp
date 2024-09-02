#include<bits/stdc++.h>
using namespace std;
int mincal(vector<int>& nums,int low,int high){
    int mini=INT_MAX;
    if(low>high) return -1;
    while(low<=high){
    int mid= low + (high-low)/2;
    if(nums[low]<=nums[mid]){
            mini=min(nums[low],mini);
            low=mid+1;
        }
        else{
            high=mid-1;
            mini=min(nums[mid],mini);
        }
    }
    return mini;
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
    cout<<mincal(nums,0,n-1)<<endl;
    // brute
    /*
    int min=nums[0];
        for(int i=1;i<nums.size();i++) if(nums[i]<min) min=nums[i];
        return min;
        */

    //optimal

}