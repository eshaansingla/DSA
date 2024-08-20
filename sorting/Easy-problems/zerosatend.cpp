#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cout<<"Enter value:";
        cin>>v[i];
    }
    int cnt=0;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == 0) {
            v.erase(v.begin() + i);
            cnt++;
        }
    }
    while(cnt>0){ 
        v.push_back(0);
        cnt--;
    }
    for(auto it:v) cout<<it<<endl;
}