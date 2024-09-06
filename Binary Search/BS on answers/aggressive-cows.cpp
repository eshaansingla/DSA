#include<bits/stdc++.h>
using namespace std;
bool fxn(vector<int>stall,int cows,int min){
    int c1=stall[0];
    int cnt=1;
    for(int i=0;i<stall.size();i++){
        if(stall[i]-c1>=min){
            c1=stall[i];
            cnt++;
        }
        if(cnt>=cows) return true;
    }
     return false;
}
int main(){
    vector<int>stall={0,3,7,4,9,10,12,15,5};
    int cows=6;
    sort(stall.begin(),stall.end());
    int i;
    for(i=1;i<=(stall[stall.size()-1]-stall[0]);i++){
        if(fxn(stall,cows,i)) continue;
        else cout<<i-1;break;
    }
    
}