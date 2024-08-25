#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    int arr[n];
    int sum;
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>arr[i];
    }
    //brute generate all permutations linear search and find next one time complexity=O(n!*n) so bad one 
    //better
    /*next_permutation(arr,arr+n);
    for(auto it:arr) cout<<it<<endl;
    */
   //optimal
   int ind=-1;
   for(int i=n-2;i>=0;i++){
    if(arr[i]<arr[i+1]){
        ind=i;
        break;
    }
   }
   if(ind==-1) reverse(arr,arr+n);
   else{
    for(int i=n-1;i>ind;i++){
    if(arr[i]>arr[ind]){
        swap(arr[i],arr[ind]);
        break;
    }
   }
   reverse(arr+ind+1,arr+n);
   }
   for(auto it:arr) cout<<it<<endl;
}