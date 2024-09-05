#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int k;
    cout<<"Enter k:";
    cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>arr[i];
    }
    //brute 
    /*
        for(int i=0;i<n;i++){
            if(arr[i]<=k) k++;
            else break;
        }
    cout<<"The missing number is: "<<k<<endl;
*/
    //optimal [2,3,4,7,10] k=5
    //         1 1 1 3 5 
    int low=0;
    int high=n-1;
    if(k<arr[0]) cout<<k<<endl;
    while(low<=high){
        int mid= low + (high-low)/2;
        int missing=arr[mid]-mid-1;
        if(missing>mid) high=mid-1;
        else low=mid+1;
    }
    cout<<low+k<<endl;
    // this code fails for size =1,2 and some cases of others. :(
}