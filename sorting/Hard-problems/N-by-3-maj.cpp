#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    cout<<"Enter a number:";
    cin>>arr[i];
    }
    //brute
    /*
        int max=INT_MIN;
        sort(nums.begin(),nums.end());
        int cnt1=0;
        int cnt2=0;
        int s;
        int m1,m2;
        for(int i=0;i<n;i++){
                s=nums[i];
            for(int j=0;j<n;j++){
                if(nums[j]==nums[i]) cnt1++;
            }
            if(cnt1>n/3){ 
                m1=nums[i];
                break;
            }
            cnt1=0;
        }
        for(int i=0;i<n;i++){
                s=nums[i];
            for(int j=0;j<n;j++){
                if(nums[j]==nums[i]) cnt2++;
            }
            if(cnt2>n/3 && s!=m1){ 
                m2=nums[i];
                break;
            }
            cnt2=0;
        }
        vector<int>res;
        if(cnt1>n/3) res.push_back(m1);
        if(cnt2>n/3 && s!=m1) res.push_back(m2);
        for(auto it:res) cout<<it<<" ";
        */
    //better
     /*   int n=arr.size();
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>max) max=arr[i];
        }

    set<int>at;
        map<int,int>hash;
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
        if(hash[arr[i]]>n/3){
             at.insert(arr[i]);
             }
    }
    vector<int>maj(at.begin(),at.end());
    for(auto it:maj) cout<<it<<" ";
    }
    */
   
   // optimal


}