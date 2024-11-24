#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&nums,int low,int high,int mid){
int left=low;
int right=mid+1;
vector<int>ans;
while(left<=mid && right<=high){
    if(nums[left]<nums[right]){ 
        ans.push_back(nums[left]);
        left++;
    }
    else{ 
        ans.push_back(nums[right]);
        right++;
        }
}
while(left<=mid) { 
        ans.push_back(nums[left]);
        left++;
    }
while(right<=high) { 
        ans.push_back(nums[right]);
        right++;
        }
for(int i=low;i<=high;i++) nums[i]=ans[i-low];
}
void mergesort(vector<int>&nums,int low,int high){
if(low>=high) return;
int mid=low+(high-low)/2;
mergesort(nums,low,mid);
mergesort(nums,mid+1,high);
merge(nums,low,high,mid);
}
int main(){
vector<int>v={69,56,44,58,70,69};
mergesort(v,0,v.size()-1);
for(auto it:v) cout<<it<<" ";
}