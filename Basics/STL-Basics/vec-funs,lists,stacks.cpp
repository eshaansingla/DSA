#include <bits/stdc++.h>
using namespace std;
int main() {
   vector<int>v;
   
   v.push_back(5);
   v.push_back(50);
   v.emplace_back(10);
   for(vector<int>::iterator it=v.begin();it!=v.end();it++) cout<<*it<<endl;
   v.push_back(45);
   cout<<endl;
   
   v.push_back(20);
   v.emplace_back(30);
   for(auto it=v.begin();it!=v.end();it++) cout<<*it<<endl;
   cout<<endl;
   
   v.push_back(1);
   v.push_back(25);
   v.emplace_back(15);
   for(auto it:v) cout<<it<<endl;
   cout<<endl;
   
   v.erase(v.begin()+1);
   for(auto it:v) cout<<it<<endl;
   cout<<endl;
   
   v.erase(v.begin()+1,v.begin()+3);
   for(auto it:v) cout<<it<<endl;
   cout<<endl;
   
   v.insert(v.begin(),60);
   for(auto it:v) cout<<it<<endl;
    cout<<endl;
    
   v.insert(v.begin()+1,90);
   for(auto it:v) cout<<it<<endl;
   cout<<endl;
   
   vector<int>v1(2,150);
   v.insert(v.begin()+1,v1.begin(),v1.end());
   for(auto it:v) cout<<it<<endl;
   cout<<endl;
   
}
