#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int x;
    cout<<"Enter x:";
    cin>>x;
    int ans=1;
    if(x==1) cout<<1;
    for(int i=2;i<x/2;i++){
        if(pow(i,n)<=x) ans=i;
        else break;
    }
    cout<<ans<<endl;
}