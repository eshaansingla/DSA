#include<bits/stdc++.h>
using namespace std;
int main(){
    /*
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>arr[i];
    }
    int d;
    cout<<"Enter number of rotations:";
    cin>>d;
    d=d%n;
    vector<int>temp;
    for(int i=0;i<d;i++){
       temp.push_back(arr[i]);
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    */
    vector<int>v;
    for(int i=1;i<=100;i++){
        v.push_back(i);
    }
    int k;
    cout<<"Enter rotations:";
    cin>>k;
    k=k%100;
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    for(auto it:v) cout<<it<<" ";   
}