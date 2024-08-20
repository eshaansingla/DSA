#include<bits/stdc++.h>
using namespace std;
int main(){
    /* the  brute force approach is creating set st and pushing common elements for uniqueness.*/
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
    vector<int>interarr;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(v[i]==v1[j]){
            if(interarr.size()==0 || interarr.back()!=v[i]){
                interarr.push_back(v[i]);
            }
             i++;
             j++;
        } else if(v[i] < v1[j]) {
            i++;
        }
        else{
             j++;
        }
    }
        for(auto it:interarr) cout<<it<<endl;
        }