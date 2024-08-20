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
    int m;
    cout<<"Enter m:";
    cin>>m;
    vector<int>v1(m);
    for(int i=0;i<m;i++){
        cout<<"Enter value:";
        cin>>v1[i];
    }
 set<int>st;
    for(int i=0;i<n;i++){
        st.insert(v[i]);
}
 for(int i=0;i<m;i++){
        st.insert(v1[i]);
}
for(auto it:st)cout<<it<<endl;
}