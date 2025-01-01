#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
        int arr[100];
        int size;
    Heap(){
        size=0;
    }
    void insert(int x){
        size++;
        arr[size]=x;
        int index=size;
        while(index>=1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else return;
        }
    }
    void print(){
        for(int i=1;i<=size;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    void pop(){
        swap(arr[1],arr[size]);
        size--;
        int i=1;
        while(i<=size){
            int l=2*i;
            int r=2*i+1;
            if(arr[i]<arr[l] && l<=size && arr[l]>arr[r]){
                swap(arr[i],arr[l]);
                i=l;
            }
            if(arr[i]<arr[r] && r<=size && arr[l]<arr[r]){
                swap(arr[i],arr[r]);
                i=r;
            }
            else{
                return;
            }
        }
    }
};
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
int arr[]={54,55,52,53,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    HeapSort(arr,n);
    print(arr,n);
    Heap *h=new Heap();
    for(int i=0;i<n;i++) h->insert(arr[i]);
    // h->print();
    // h->pop();
    // h->print();
}