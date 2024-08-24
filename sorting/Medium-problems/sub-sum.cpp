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
    
    //brute
    /* int sum=0;
    int maxi=INT64_MIN;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maxi=max(sum,maxi);
        }
    }
    cout<<maxi<<endl;
    */
   //optimal
   sum=0;
   int maxi=INT_MIN;
   for(int i=0;i<n;i++){
    sum+=arr[i];
    maxi=max(maxi,sum);
    if(sum<0) sum=0;
   }
    cout<<maxi<<endl;
}
