/*Design the Logic to Find a Missing Number in a Sorted Array.*/
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high){
        mid=low + (high-low)/2;
        if(arr[mid]==mid+1){
            low=mid+1;
        }
        else high=mid-1;
    }
    cout<<low+1;
}