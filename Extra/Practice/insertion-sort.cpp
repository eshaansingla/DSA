#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,5,4,3,7,6,8,9,11,23,21,9,2,1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}