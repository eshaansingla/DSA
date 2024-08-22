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
    cout<<"Enter sum:";
    cin>>sum;
    //brute force
   /* int k;
    int cnt=0;
    int m=0;
    for(int j=0;j<n;j++){
        k=0;
    for(int i=j;i<n;i++){
            k+=arr[i];
            cnt++;
            if(k==sum){
                m++;
            }
        }
}
cout<<"The maximum number of subarrays:"<<m<<endl;
cout<<"Total subarrays:"<<cnt<<endl;*/
}