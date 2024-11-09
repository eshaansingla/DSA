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
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && arr[left]<arr[largest]){
            largest=left;
        }
        if(right<n && arr[right]<arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            Heapify(arr,n,largest);
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
int main(){
    Heap *h=new Heap();
    h->insert(54);
    h->insert(53);
    h->insert(55);
    h->insert(50);
    h->insert(52);
    h->insert(51);
    h->print();
    h->pop();
    h->print();
    int arr[]={53,55,45,54,36,89,59};
    Heapify(arr,sizeof(arr)/sizeof(arr[0]),0);
}