#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v;
    v.push_back(5);
    cout<<v[0]<<endl;
    vector<int>n(5,10);
    cout<<n[0]<<","<<n[1]<<","<<n[2]<<","<<n[3]<<","<<n[4]<<endl;
    vector<int>l(5);
    cout<<l[0]<<","<<l[1]<<","<<l[2]<<","<<l[3]<<","<<l[4]<<endl;
    l.push_back(500);
    cout<<l[0]<<","<<l[1]<<","<<l[2]<<","<<l[3]<<","<<l[4]<<","<<l[5]<<endl;
    l.emplace_back(75);
    cout<<l[0]<<","<<l[1]<<","<<l[2]<<","<<l[3]<<","<<l[4]<<","<<l[5]<<","<<l[6]<<endl;
    vector<pair<int,int>>m;
    m.push_back({1,2});
    cout<<m[0].first<<","<<m[0].second<<endl;
    vector<pair<int,int>>p;
    p.emplace_back(3,4);
    cout<<p[0].first<<","<<p[0].second<<endl;
    vector<pair<int,int>>::iterator it=p.begin();
    cout << it->first << "," << it->second << endl;
    vector<int>::iterator it1=v.begin();
    cout<<*it1<<endl;
}
