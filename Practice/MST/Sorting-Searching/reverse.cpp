#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element: ";
        cin>>arr[i];
    }
    for(int i=0;i<n/2;i++){
        int temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
    int i=0;
    int j=n-1;
    bool flag=1;
    while(i<=j){
        if(arr[i]==arr[j]){
            i++;
            j--;
        }
        else {
            flag=0;
            break;
        }
    }
    if(flag){
        cout<<"pali"<<endl;
    }
    else cout<<"not pali"<<endl;
}