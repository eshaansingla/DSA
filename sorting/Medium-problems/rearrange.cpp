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
    int j=0;
    //brute
    /* vector<int>pos,neg,final;
    for(int i=0;i<n;i++){
        if(arr[i]>0) pos.emplace_back(arr[i]);
        else neg.emplace_back(arr[i]);
    }
    for(int i=0;i<n/2;i++){
        final.emplace_back(pos[i]);
        final.emplace_back(neg[i]);
    }
    for(auto it:final) cout<<it<<endl; */

    //optimal
    int final[n];
    int j=0;
    int k=1;
    for(int i=0;i<n;i++){
        if(arr[i]>0){ 
            final[j]=arr[i];
            j+=2;
            }
        else{
            final[k]=arr[i];
            k+=2;
        }
    }

}