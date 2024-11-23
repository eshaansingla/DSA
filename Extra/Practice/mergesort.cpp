#include<iostream>
using namespace std;
void merge(int *a,int low,int high,int mid,int n){
if(low>high) return;
int left=low;
int right=mid+1;
int temp[n];
int i=0;
while(left<=mid && right<=high){
    if(a[left]<=a[right]){
        temp[i]=a[left];
        left++;
        i++;
    }
    else{
        temp[i]=a[right];
        right++;
        i++;
    }
}
while(left<=mid){
    temp[i]=a[left];
        left++;
        i++;
}
while(right<=high){
    temp[i]=a[right];
        right++;
        i++;
}
for (int j = 0; j < i; j++) {
        a[low + j] = temp[j];
    }
}
void mergesort(int *a,int low,int high,int n){
if(low>=high) return;
int mid= low + (high-low)/2;
mergesort(a,low,mid,n);
mergesort(a,mid+1,high,n);
merge(a,low,high,mid,n);
}
int main(){
    int arr[]={1,2,5,4,3,7,6,8,9,11,23,21,9,2,1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}