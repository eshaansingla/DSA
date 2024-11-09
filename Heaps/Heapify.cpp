#include<bits/stdc++.h>
using namespace std;
void Heapify(int arr[],int n,int i){
        int largest=i;
        int left;
        int right;
        left=2*i+1;
        right=2*i+2;
        if(left<n && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<n && arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            Heapify(arr,n,largest);
        }
    }
    void print(int arr[],int n){
        for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
int arr[]={53,55,45,54,36,89,59};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=n/2;i>=0;i--) Heapify(arr,n,i);
    print(arr,n);
}