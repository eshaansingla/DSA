#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    int sum;
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>arr[i];
    }
    //brute merge sort or direct sort command
    //better
    /*int c1=0;
    int c2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) c1++;
        else if(arr[i]==1) c2++;
    }
    for(int i=0;i<c1;i++){
        arr[i]=0;
    }
    for(int i=c1;i<c1+c2;i++){
        arr[i]=1;
    }
    for(int i=c1+c2;i<n;i++){
        arr[i]=2;
    }*/
   //optimal
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[high],arr[mid]);
            high--;
        }
        else mid++;
    }
    
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}