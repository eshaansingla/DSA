#include<iostream>
using namespace std;
int main(){
    int search,n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter search: ";
    cin>>search;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element: ";
        cin>>arr[i];
    }
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid= low +(high-low)/2;
        if(search>arr[mid]){
            low=mid+1;
        }
        else if(search<arr[mid]){
            high=mid-1;  
        }
        else {
            cout<<mid<<endl;
        break;}
    }
}