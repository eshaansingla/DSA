#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>arr[i];
    }
    bool flag=true;
    for(int i=0;i<n;i++){
    if(arr[i]>arr[i+1]){
        flag=false;
    }
    }
    cout<<flag<<endl;
}