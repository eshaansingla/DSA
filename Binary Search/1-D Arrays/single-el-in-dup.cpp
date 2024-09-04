#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
       cout<<"Enter a number:";
       cin>>nums[i];
    }
    // brute
    /*if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i==0){
            if(nums[i]!=nums[i+1]) {
                cout<< nums[i];
                break;
                }
            }
            else if(i==nums.size()-1){
                if(nums[i]!=nums[i-1]){
                cout<< nums[i];
                break;
                }
            }
            else{
                if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]){
                cout<< nums[i];
                break;
                }
            }
        }*/

    // BETTER WAY TO WRITE BRUTE
    /*
        bool flag=false;
        if(n==1) {
            cout<<nums[0];
            flag=true;
            }
        if(nums[0]!=nums[1]) {
            cout<<nums[0];
            flag=true;
            }
        if(nums[n-1]!=nums[n-2]) {
            cout<<nums[n-1];
            flag=true;
            }
        if(flag==false){
        for(int i=1;i<n-1;i++){
                if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]) {
                    cout<<nums[i];
                    break;
                    }
        }
        }
        */

    //better
        /*
    int xor1=0;
    for(int i=0;i<nums.size();i++) xor1^=nums[i];
    cout<< xor1;
    */

   //optimal
    bool flag=false;
     if(n==1) {
            cout<<nums[0];
            flag=true;
            }
        if(nums[0]!=nums[1]) {
            cout<<nums[0];
            flag=true;
            }
        if(nums[n-1]!=nums[n-2]) {
            cout<<nums[n-1];
            flag=true;
            }
        int low=1,high=n-2;
        int mid;
        if(flag==false){
        while(low<=high){
            mid= low + (high-low)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){ 
                cout<<nums[mid];
                break;
                }
            if((mid%2==0 && nums[mid]!=nums[mid+1]) || (mid%2!=0 && nums[mid]!=nums[mid-1])) high=mid-1;
            else low=mid+1;
        }
    }
}

    