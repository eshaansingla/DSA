#include<iostream>
using namespace std;
void bubblesort(int *a,int n){
for(int i=0;i<n;i++){
    for(int j=i+1;j<n-i;j++){
        if(a[j]<a[j-1]){
            int temp=a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
        }
    }
}
}
void insertion(int *a,int n){
    for(int i=0;i<n;i++){
        int key=a[i];
        int j=i+1;
    while(j<n && a[j]<key){
        if(a[j]<a[j-1]){
            int temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
        j++;
    }
    }
}
void selection(int *a,int n){
    for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(a[mini]>a[j]) mini=j;
        }
    int temp=a[i];
    a[i]=a[mini];
    a[mini]=temp;
    }
}
void merge(int *a,int low,int mid,int high){
int left=low;
int right=mid+1;
int n=high-low+1;
int temp[n];
int i=0;
while(left<=mid && right<=high){
    if(a[left]<=a[right]){
        temp[i]=a[left];
        left++;
    }
    else{
        temp[i]=a[right];
        right++;
    }
    i++;
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
for(int j=0;j<i;j++){
    a[j+low]=temp[j];
}
}
void mergesort(int *a,int low,int high){
if(low>=high) return;
int mid=low+(high-low)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,mid,high);
}
int partition(int *a,int low,int high){
int pivot=a[low];
int i=low;
int j=high;
while(i<j){
    while(a[i]<=pivot && i<high) i++;
    while(a[j]>pivot && j>low) j--;
    if(i<j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
 int temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
void qs(int *a,int low,int high){
if(low>=high){
    return;
}
int pindex=partition(a,low,high);
qs(a,low,pindex-1);
qs(a,pindex+1,high);
}
void quicksort(int *a,int n){
qs(a,0,n-1);
}
int main(){
int n;
cout<<"Enter number of elements: ";
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cout<<"Enter an element: ";
    cin>>arr[i];
}
//bubblesort(arr,n);
//insertion(arr,n);
//selection(arr,n);
//mergesort(arr,0,n-1);
quicksort(arr,n);
for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}