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
    int sum=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            sum+=arr[i];
        }
        else sum-=arr[i];
    }
    cout<<sum<<endl;
}