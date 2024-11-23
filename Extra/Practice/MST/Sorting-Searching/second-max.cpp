#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    int max=INT8_MIN;;
    for(int i=0;i<n;i++){
        cout<<"Enter element: ";
        cin>>arr[i];
    }
    int max2=0;
    for(int i=0;i<n;i++){
       if(max<arr[i]){
        max2=max;
        max=arr[i];
        }
        else if(max2<arr[i]) max2=arr[i];
    }
    cout<<max<<endl;
    cout<<max2<<endl;
}