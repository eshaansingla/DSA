#include<iostream>
using namespace std;
void selectionSort(int *a,int n){
cout<<endl;
cout<<"Doing Selection Sort............"<<endl;
for(int i=0;i<n-1;i++){
int mini=i;
for(int j=i+1;j<n;j++){
    if(a[mini]>a[j])  mini=j;
}
if(mini!=i) swap(a[i],a[mini]);
}
}
void insertionSort(int*a,int n){ 
cout<<endl;
cout<<"Doing Insertion Sort............"<<endl;
for(int i=0;i<n;i++){
    int key=a[i];
    int j=i;
while(j>0 && a[j-1]>key){
    a[j]=a[j-1];
    j--;
    a[j]=key;
}
}
}
void bubbleSort(int *a,int n){
cout<<endl;
cout<<"Doing Bubble Sort............"<<endl;
for(int i=0;i<n;i++){
    bool flag=0;
    for(int j=0;j<n-i-1;j++){
        if(a[j+1]<a[j]){
            swap(a[j+1],a[j]);
            flag=1;
        }
    }
    if(!flag) break;
}
}
int partition(int *a,int low,int high){
int pivot=a[low];
int cnt=0;
for(int i=low+1;i<=high;i++){
    if(a[i]<pivot) cnt++;
}
int pivotidx=low+cnt;
swap(a[low],a[pivotidx]);
int i=low,j=high;
while(i<pivotidx && j>pivotidx){
    while(a[i]<=pivot && i<pivotidx) i++;
    while(a[j]>pivot && j>pivotidx) j--;
    if(i<pivotidx && j>pivotidx) swap(a[i++],a[j--]);
}
return pivotidx;
}
void quickSort(int*a,int low,int high){
if(low>=high) return;
int p=partition(a,low,high);
quickSort(a,low,p-1);
quickSort(a,p+1,high);
}
//   MERGE SORT
void merge(int *a,int low,int mid,int high){
int left=low;
int right=mid+1;
int i=0;
int temp[high+1];
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
for(int i=low;i<=high;i++){
    a[i]=temp[i-low];
}
}
void mergeSort(int *a,int low,int high){
if(low>=high) return;
int mid=low + (high-low)/2;
mergeSort(a,low,mid);
mergeSort(a,mid+1,high);
merge(a,low,mid,high);
}
int main(){
    int arr[]={9,4,1,5,7,6,3,9,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    // for(int i=0;i<n;i++){
    //     cout<<"Enter element at position "<<i+1<<": ";
    //     cin>>arr[i];
    // }
    //selectionSort(arr,n);
    //bubbleSort(arr,n);
    //insertionSort(arr,n);
    //mergeSort(arr,0,n-1);
    quickSort(arr,0,n-1);
    for(auto it:arr) cout<<it<<" ";
}
