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
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
 /*set<int>st;
    for(int i=0;i<n;i++){
        st.insert(v[i]);
}
 for(int i=0;i<m;i++){
        st.insert(v1[i]);
}
for(auto it:st)cout<<it<<endl;*/
    vector<int>unionarr;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(v[i]<=v1[j]){
            if(unionarr.size()==0 || unionarr.back()!=v[i]){
                unionarr.push_back(v[i]);
            }
             i++;
        }
        else{
            if(unionarr.size()==0 || unionarr.back()!=v1[j]){
                unionarr.push_back(v1[j]);
            }
             j++;
        }
    }
    while(i<n){
            if(unionarr.size()==0 || unionarr.back()!=v[i]){
                unionarr.push_back(v[i]);
            }
             i++;
        }
        while(j<m){
             if(unionarr.size()==0 || unionarr.back()!=v1[j]){
                unionarr.push_back(v1[j]);
            }
             j++;
        }
        for(auto it:unionarr) cout<<it<<endl;
        }