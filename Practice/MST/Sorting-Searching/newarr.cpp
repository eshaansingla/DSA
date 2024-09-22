#include<iostream>
using namespace std;
int main(){
    int sum,n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter sum: ";
    cin>>sum;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element: ";
        cin>>arr[i];
    }
    int i=0,j=0;
    while(i<n){
        for(j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
            if(arr[i]+arr[j]+arr[k]==sum){
                cout<<"{"<<arr[i]<<","<<arr[j]<<","<<arr[k]<<"}"<<endl;
            }
        }
        j++;
        }
        i++;
    }
}