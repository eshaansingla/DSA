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
    int k=0;
    int cnt=0;
    for(int j=1;j<n;j++){
        if(arr[k]!=arr[j]){
            arr[k+1]=arr[j];
            k++;
        }
        else{
            cnt++;
        }
    }
     for(int i=0;i<n-cnt;i++){
        cout<<arr[i]<<endl;
     }
}