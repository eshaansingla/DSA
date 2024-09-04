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
    //brute
    /*
        int maxi=0;
        if(n==1) cout<<0<<endl;
        if(n==2){
            if(nums[0]>nums[1]) cout<<0<<endl;
            else cout<<1<<endl;
        }
        bool flag=false;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){ 
                maxi=max(maxi,i);
                flag=true;
            }
        }
        int a=nums[0];
        int b=0;
        for(int i=0;i<n;i++){
            if(nums[i]>a){ 
                a=nums[i];
                b=i;
            }
        }
        if (flag==true)cout<<maxi<<endl;
        else cout<<b<<endl;
        */
       // better
       /* 
       for(int i=0;i<n;i++){
            if((i==0 || nums[i]>nums[i-1])&&(i==n-1 || nums[i]>nums[i+1])){
                cout<<i<<endl;
                }
        } 
        */
       //optimal
        if(n==1) cout<<0<<endl;
        if(nums[0]>nums[1]) cout<<0<<endl;
        if(nums[n-1]>nums[n-2]) cout<<n-1<<endl;
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid= low + (high-low)/2;
            if(nums[mid]>nums[mid+1] && nums[mid-1]<nums[mid]){ 
                cout<<mid<<endl;
            }
            else if(nums[mid]>nums[mid+1]) high=mid-1;
            else if(nums[mid]>nums[mid-1]) low=mid+1;
            else low=mid+1;
        }
}