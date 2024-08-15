#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element number "<<i+1<<":";
        cin>>arr[i];
    }
    int m=*max_element(arr,arr+n);
    int hash[m+1];
    for(int i=0;i<m+1;i++){
        hash[i]=0;
    }
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }
    int num;
    while(1>0){
        cout<<endl<<"Enter number to find:";
        cin>>num;
        if(num>m) cout<<0;
        else cout<<hash[num];
    }
}