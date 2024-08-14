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
    
   list<int>ls;
   ls.push_back(2);
   ls.push_front(1);
   for(auto it:ls) cout<<it<<endl;
   cout<<endl;
   
   ls.pop_front();
   for(auto it:ls) cout<<it<<endl;
   cout<<endl;
   
   stack<int>st;
   for(int i=0;i<5;i++) st.push(i);
   cout<<st.top()<<endl;
   cout<<st.size()<<endl;
   st.pop();
   cout<<st.top()<<endl;
   cout<<st.empty()<<endl;
   cout<<endl;
   
   stack<int>st1;
   for(int i=3;i<8;i++) st1.push(i);
   cout<<st.top()<<endl;
   cout<<st.size()<<endl;
   st.pop();
   cout<<st.top()<<endl;
   cout<<st.empty()<<endl;
   cout<<endl;
   
   queue<int>q;
   q.push(1);
   q.push(9);
   q.push(6);
   q.push(8);
   cout<<q.front()<<endl;
   cout<<q.size()<<endl;
   q.pop();
   cout<<q.front()<<endl;
   cout<<q.empty()<<endl;
   cout<<endl;
   
   priority_queue<int>q1; //max heap
   q1.push(1);
   q1.push(9);
   q1.push(6);
   q1.push(8);
   cout<<q1.top()<<endl;
   cout<<q1.size()<<endl;
   q1.pop();
   cout<<q1.top()<<endl;
   cout<<q1.empty()<<endl;
   cout<<endl;
   
   priority_queue<int,vector<int>,greater<int>>q2; //min heap
   q2.push(1);
   q2.push(9);
   q2.push(6);
   q2.push(8);
   cout<<q2.top()<<endl;
   cout<<q2.size()<<endl;
   q2.pop();
   cout<<q2.top()<<endl;
   cout<<q2.empty()<<endl;
   cout<<endl;
   
  set<int> s;
  for(int i = 6; i < 15; i++) s.insert(i);
  for(int i = 1; i < 12; i++) s.insert(i);
  for(int it : s) cout << it << " ";
  cout<<endl;

   multiset<int>ms;
   ms.emplace(1);
   ms.emplace(2);
   ms.emplace(3);
   ms.emplace(4);
   ms.emplace(6);
   ms.emplace(9);
   ms.emplace(2);
   ms.emplace(0);
   for(auto it:ms) cout<<it<<endl;
   cout<<endl;
   auto it=ms.find(2);
   auto it1=ms.find(4);
   ms.erase(it,it1);
   for(auto it:ms) cout<<it<<endl;

   map<int,int>mpp;
   map<pair<int,int>,int>mpp2;
   mpp[1]=2;
   mpp2[{2,3}]=10;
   for(auto it:mpp) cout<<it.first<<" "<<it.second<<endl;
   for(auto it:mpp2) cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
   cout<<endl;

    vector<int> v5;
    v5.push_back(1);
    vector<int> temp = {5, 2, 5, 5, 6, 9, 8, 7, 1, 2, 6, 52, 2, 0, 10};
    v5.insert(v5.end(), temp.begin(), temp.end());

    sort(v5.begin(), v5.end());

    for(auto it : v5) cout << it << endl;
   cout<<endl;
   int maxi=*max_element(v5.begin(),v5.end());
   cout<<maxi;
   cout<<endl<<__builtin_popcount(5);

   string perm="69584";
   sort(perm.begin(),perm.end());
   do{
      cout<<perm<<endl;
   }while(next_permutation(perm.begin(),perm.end()));
   cout<<endl;
   do{
      cout<<perm<<endl;
   }while(next_permutation(perm.begin()+2,perm.end()));
   cout<<endl;
   do{
      cout<<perm<<endl;
   }while(next_permutation(perm.begin(),perm.end()-2));
   cout<<endl;
   
  return 0;
}
