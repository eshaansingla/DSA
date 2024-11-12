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
        int index=size;
        arr[size]=x;
        size++;
        while(index>0){
            int parent=index/2;
            if(arr[parent]<arr[index]){ 
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else return;
        }
    }
    void print(){
        for(int i=0;i<size;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    void pop(){
        int index=0;
        arr[index]=arr[size-1];
        size--;
        int left=1;
        int right=2;
        while(index<size){
            if(arr[left]>arr[right] && arr[left]>arr[index] && left<size){
                swap(arr[left],arr[index]);
                index=left;
                left=2*index;
            }
            if(arr[left]<arr[right] && arr[right]>arr[index] && right<size){
                swap(arr[right],arr[index]);
                index=right;
                left=2*index+1;
            }
            else{
                return;
            }
        }
    }
};
void Heapify(int arr[],int n,int i){
int largest=i;
int left=2*i;
int right=2*i+1;
if(left<=n && arr[left]>arr[largest]) largest=left;
if(right<=n && arr[right]>arr[largest]) largest=right;
if(largest!=i){
    swap(arr[largest],arr[i]);
    Heapify(arr,n,largest);
}
}
void HeapSort(int arr[],int size){
int t=size;
while(t>0){
    swap(arr[1],arr[t]);
    t--;
    Heapify(arr,t,1);
}
}
int main(){
    Heap *h=new Heap();
    /*h->insert(54);
    h->insert(53);
    h->insert(55);
    h->insert(50);
    h->insert(52);
    h->insert(51);
    h->print();
    h->pop();
    h->print();*/
    int arr[6]={-1,55,53,54,52,50};
    int n=5;
    /*for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }*/
    HeapSort(arr,n);
    for(int i=1;i<=n;i++) cout<<arr[i]<<" "; 
}