#include<iostream>
using namespace std;
int parting(int *a,int low,int high){
int pivot = a[high];
    int i = low;
    int j = high-1;
while(i<=j){
    while(a[i]<=pivot && i<high) i++;
    while(a[j]>pivot && j>=low) j--;
    if(i<j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
int temp = a[high];
    a[high] = a[i];
    a[i] = temp;
    return i;
}
void qs(int *a,int low,int high){
    if(low<high){
    int pindex=parting(a,low,high);
    qs(a,low,pindex-1);
    qs(a,pindex+1,high);
}
}
int main(){
    int arr[]={1,2,5,4,3,7,6,8,9,11,23,21,9,2,1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    qs(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}