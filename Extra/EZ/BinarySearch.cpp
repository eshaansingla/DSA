#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&arr,int low,int high,int search){
if(low>high) return -1;
int mid=low+(high-low)/2;
if(search>arr[mid]) binarySearch(arr,mid+1,high,search);
else if(search<arr[mid]) binarySearch(arr,low,mid-1,search);
else return mid+1;
}
pair<int,int>FandL(vector<int>&arr,int low,int high,int search){
low=0;
int mid;
high=arr.size()-1;
int f=-1;
int l=-1;
while(low<=high){
    if(low>high) break;
    mid=low + (high-low)/2;
    if(search>arr[mid]) low=mid+1;
    else if(search==arr[mid]){
        high=mid-1;
        f=mid;
    }
    else high=mid-1;
}
low=0;
high=arr.size()-1;
while(low<=high){
    if(low>high) break;
    mid=low + (high-low)/2;
    if(search>arr[mid]) low=mid+1;
    else if(search==arr[mid]){ 
        low=mid+1;
        l=mid;
        }
    else high=mid-1;
}
return {f,l};
}
void peak(vector<int>&arr,int low,int high){
    int mid;
    while(low<=high){
        mid=low +(high-low)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            cout<<"PEAK= "<<arr[mid];
            break;
        }
        else if(arr[mid-1]>arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) {
        cout<<"Enter element: ";
        cin>>nums[i];
        }
    int low=0;
    int high=n-1;
    int mid;
    int search;
    cout<<"Enter search element: ";
    cin>>search;
    /*
    while(low<=high){
        if(low>high) break;
        mid=low + (high-low)/2;
        if(search>nums[mid]) low=mid+1;
        else if(search==nums[mid]){
            cout<<"Found at "<<mid+1<<endl;
            break;
        }
        else high=mid-1;
    }
    */
   //cout<<binarySearch(nums,low,high,search)<<endl;
   //cout<<FandL(nums,low,high,search).first<<" "<<FandL(nums,low,high,search).second;
   peak(nums,low,high);
}