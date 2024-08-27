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
}