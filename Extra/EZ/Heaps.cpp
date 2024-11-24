#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size=0;
    Heap(){

    }
    void insert(int x){
        int index=++size;
        arr[index]=x;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){ 
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else return;
        }
    }
    void print(){
    for(int i=1;i<=size;i++) cout<<arr[i]<<endl;
    }
    void del(){
        arr[1]=arr[size];
        size--;
        int i=1;
        int largest=i;
        while(i<=size){
            int left=2*i;
            int right=2*i+1;
            if(arr[i]<arr[left] && left<=size && arr[left]>arr[right]){
                largest=left;
            }   
            else if(arr[i]<arr[right] && right<=size && arr[left]<arr[right]){
                largest=right;
            }
            if(largest!=i){
            swap(arr[largest],arr[i]);
            i=largest;
        }   
        else break;
        } 
    }
};
void Heapify(vector<int>&arr,int n,int i){
int largest=i;
int left=2*i;
int right=2*i+1;
if(arr[largest]<arr[left] && left<n ) largest=left;
if(arr[largest]<arr[right] && right<n ) largest=right;
if(largest!=i){
    swap(arr[largest],arr[i]);
    Heapify(arr,n,largest);
}
}
int main(){
Heap*h=new Heap();
vector<int>nums={-1,56,55,65,60,67,69,50,51};
for(int i=0;i<nums.size();i++){
    h->insert(nums[i]);
}
/*
h->print();
cout<<endl;
h->del();
h->print();
*/
for(int i=(nums.size()-1)/2; i>0 ;i--) Heapify(nums,nums.size(),i);
for(int i=1;i<nums.size();i++) cout<<nums[i]<<" ";
}