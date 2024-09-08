/*Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent 
elements if they are in wrong order. Code the Bubble sort with the following elements: 
64 34 25 12 22 11 90*/
#include<iostream>
using namespace std;
int main(){
    int arr[]={64,34,25,12,22,11,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int j=1;j<n;j++){
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            int temp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;
        }
    }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}