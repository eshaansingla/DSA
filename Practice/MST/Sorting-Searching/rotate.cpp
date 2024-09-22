#include<iostream>
using namespace std;
void reverse(int *arr,int a,int b){
    int i,j;
for(i=a,j=b;i<j;i++,j--){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;    
}
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element: ";
        cin>>arr[i];
    }
    int k;
    cout<<"Enter k:";
    cin>>k;
    k=k%n;
    reverse(arr,0,n-1);
    reverse(arr,0,k);
    reverse(arr,k+1,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}