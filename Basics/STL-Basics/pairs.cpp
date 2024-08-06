#include<bits/stdc++.h>
using namespace std;
void pairs(){
  pair<int,char>p={1,'w'};
  cout<<p.first<<" "<<p.second<<endl;
}
void pairsmulti(){
    pair<int,pair<int,int>>p={1,{2,3}};
     cout<<p.first<<" "<<p.second.first<<","<<p.second.second<<endl;
}
void samplearray(){
    pair<int,char>p[]={{1,'a'},{3,'e'},{5,'s'}};
    cout<<p[0].first<<","<<p[0].second<<endl;
    cout<<p[1].first<<","<<p[1].second<<endl;
    cout<<p[2].first<<","<<p[2].second<<endl;
}
int main(){
  pairs();
  pairsmulti();
  samplearray();
}
