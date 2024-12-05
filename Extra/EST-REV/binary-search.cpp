#include<bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int>&v,int low,int high,int search){
if(low>high) return -1;
int mid= low + (high-low)/2;
if(search>v[mid]) return BinarySearch(v,mid+1,high,search);
else if(search==v[mid]) return mid;
else return BinarySearch(v,low,mid,search);
}
int first_occ(vector<int>&v,int low,int high,int search){
if(low>high) return -1;
int mid= low + (high-low)/2;
if(search>v[mid]) return first_occ(v,mid+1,high,search);
if(search==v[mid]){
int ans=first_occ(v,low,mid-1,search);
return (ans != -1) ? ans : mid;
}   
else return first_occ(v,low,mid,search);
}
int last_occ(vector<int>&v,int low,int high,int search){
if(low>high) return -1;
int mid= low + (high-low)/2;
if(search>v[mid]) return last_occ(v,mid+1,high,search);
if(search==v[mid]){
int ans=last_occ(v,mid+1,high,search);
return (ans != -1) ? ans : mid;
}
else return last_occ(v,low,mid-1,search);
}
int first_occ(vector<int>&v,int low,int high,int search){
int ans=-1;
while(low<=high){
    int mid =low +(high-low)/2;
    if(v[mid]>search) high=mid-1;
    else if(v[mid]==search){
        ans=mid;
        high=mid-1;
    }
    else low=mid+1;
}
return ans;
}
int last_occ(vector<int>&v,int low,int high,int search){
int ans=-1;
while(low<=high){
    int mid =low +(high-low)/2;
    if(v[mid]>search) high=mid-1;
    else if(v[mid]==search){
        ans=mid;
        low=mid+1;
    }
    else low=mid+1;
}
return ans;
}
int peak(vector<int>&v){
int low=0;
int high=v.size()-1;
int mid;
while(low<=high){
    mid=low + (high-low)/2;
    if(v[mid]<v[mid+1]){
        low=mid+1;
    }
    else{
        high=mid;
    }
    if(v[mid]>v[mid+1] && v[mid]>v[mid-1]){
        return v[mid];
    }
}
}
void pivot(vector<int>&v){
int low=0;
int high=v.size()-1;
int mid;
while(low<=high){
    mid=low+(high-low)/2;
    if(v[mid]>=v[0]){
        low=mid+1;
    }
    else high=mid-1;
}
cout<<v[low]<<endl;
}
int main(){
vector<int>v={8,9,10,12,2,3};
 sort(v.begin(),v.end());
 int low=0;
 int search=4;
 int high=v.size()-1;
 int mid;
 while(low<=high){
     mid=low +(high-low)/2;
     if(v[mid]>search) high=mid-1;
     else if(v[mid]==search){
         cout<<mid<<endl;
         break;
     }
     else low=mid+1;
 }
cout<<first_occ(v,0,v.size()-1,4)<<" "<<last_occ(v,0,v.size()-1,4);
cout<<peak(v)<<endl;
pivot(v);
}