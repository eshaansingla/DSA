#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int prices[n];
    int sum;
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>prices[i];
    }
    //brute
   /* int prof=0;
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                prof=prices[j]-prices[i];
                total=max(total,prof);
            }
        }
        if(total>0) cout<<total<<endl;
        else cout<<0<<endl; */
        //optimal
        int prof=0;
        int mini=prices[0];
        int cost;
        for(int i=0;i<n;i++){
           cost=prices[i]-mini;
           prof=max(prof,cost);
           mini=min(mini,prices[i]);
        }
        cout<<prof<<endl;
}