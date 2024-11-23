/* Implement the Binary search algorithm regarded as a fast search algorithm with run-time 
complexity of Ο(log n) in comparison to the Linear Search. */
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,7,9,10,12,15};
    int low=0;
    int high=sizeof(arr)/sizeof(arr[0])-1;
    int k;
    cout<<"Enter the number to be found: ";
    cin>>k;
    int mid;
    while(low<=high){
        mid=low + (high-low)/2;
        if(arr[mid]==k) cout<<mid<<endl; break;
        if(k>arr[mid]) low=mid+1;
        else high=mid-1;
    }
    if(low>high) cout<<"NAH";
}