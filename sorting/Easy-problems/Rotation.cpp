#include<bits/stdc++.h>
using namespace std;
int main(){
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