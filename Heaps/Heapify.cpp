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
void HeapSort(int arr[],int n){
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }
    int size=n;
    while(size>0){
        swap(arr[size-1],arr[0]);
        size--;
        Heapify(arr,size,0);
    }
}

int main(){
int arr[]={53,55,45,54,36,89,59};
    int n=sizeof(arr)/sizeof(arr[0]);
    HeapSort(arr,n);
    print(arr,n);
}