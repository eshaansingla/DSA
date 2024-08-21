#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>v[i];
    }
    int cnt=0;
    int no=0;
    for(int i=0;i<n;i++){
        if(v[i]==1){
            no++;
            cnt=max(no,cnt);
        }
        else{
            no=0;
        }
    }
    cout<<"Max number of consecutive 1s are: "<<cnt<<endl;
}
