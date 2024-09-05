#include<bits/stdc++.h>
//optimal
int power(int a,int p){
    int ans=1;
while(p>0){ 
    ans*=a;
    p--;
}
return ans;
}
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int x;
    cout<<"Enter x:";
    cin>>x;
    int ans=1;
    //brute 
    /*
    if(x==1) cout<<1;
    for(int i=2;i<x/2;i++){
        if(pow(i,n)<=x) ans=i;
        else break;
    }
    cout<<ans<<endl;
    */

   //optimal
   int low=1;
   int high=x/2;
   int mid;
   int pw;
   if(x==1 || x==0) cout<<x<<endl;
   while(low<=high){
    mid=low + (high-low)/2;
    pw=power(mid,n);
    if(pw==x){
        ans=mid;
        cout<<ans<<endl;
        break;
    }
    else if(pw>x) high=mid-1;
    else {
        low=mid+1;
        ans=mid;
        }
   }
    cout<<ans<<endl;
}