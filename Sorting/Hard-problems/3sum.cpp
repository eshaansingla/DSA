#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
    cout<<"Enter a number:";
    cin>>nums[i];
    }
    //brute
   /* vector<vector<int>>v;
        set<vector<int>> uniqueTriplets;
        vector<int> triplet;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        uniqueTriplets.insert(triplet);
                }
            }
        }
    }
     for (auto triplet : uniqueTriplets) {
            v.push_back(triplet);
        }
    */

   //better
   /*vector<vector<int>>v;
        set<vector<int>> uniqueTriplets;
        vector<int> triplet;
        int search;
    for(int i=0;i<n;i++){
        set<int>st;
        for(int j=i+1;j<n;j++){
            search=(nums[i]+nums[j])*-1;
                if(nums[j]==search && i!=j){
                    triplet = {nums[i], nums[j],search};
                        sort(triplet.begin(), triplet.end());
                        uniqueTriplets.insert(triplet);
                }
                st.insert(nums[j]);
        }
    }
     for (auto triplet : uniqueTriplets) {
            v.push_back(triplet);
        }
    */
   //optimal
        vector<vector<int>>ans;
        sort(nums,nums+n);
        int j,k,sum;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            j=i+1;
            k=n-1;
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;  
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            for(int p=0;p<3;p++){
                cout<<ans[i][p]<<",";
            }
            cout<<endl;
        }
   

}