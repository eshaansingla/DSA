#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
private:
map<T,vector<T>>adj;
public:
void add(T f,T s,int dxn){
adj[f].emplace_back(s);
if(dxn==0) adj[s].emplace_back(f);
}
void print(){
    for(auto it:adj){
        cout<<it.first<<"->";
        for(auto it1:it.second) cout<<it1<<",";
        cout<<endl;
    }
}
void bfs(vector<T>&ans,T node,map<T,bool>&b){
queue<T>q;
q.push(node);
b[node]=1;
while(!q.empty()){
    auto res=q.front();
    q.pop();
    ans.push_back(res);
for (auto it:adj[res]){
    if(!b[it]){
        q.push(it);
        b[it]=1;
    }
}
}
}
void BFStrav(T node){
    vector<T>ans;
    map<T,bool>b;
    bfs(ans,node,b);
    for(auto it1:adj){
    if(!b[it1.first]){ 
        bfs(ans,it1.first,b);
    }
}
for(auto k:ans){
    cout<<k<<endl;
}
}
void DFS(vector<T>&ans1,T node1,map<T,bool>&b1){
b1[node1]=true;
ans1.emplace_back(node1);
for(auto it:adj[node1]){
    if(!b1[it]) DFS(ans1,it,b1);
}
}
void DFStrav(T data){
vector<T>ans1;
map<T,bool>b1;
DFS(ans1,data,b1);
for(auto it:adj){
    if(!b1[it.first]) DFS(ans1,it.first,b1);
}
for(auto it:ans1) cout<<it<<endl;
}
bool BFSloop(map<T,bool>&visited,map<T,T>&parent,T data){
queue<T>q;
q.push(data);
visited[data]=1;
while(!q.empty()){
    auto sh=q.front();
    q.pop();
    for(auto it:adj[sh]){
        if(!visited[it]){ 
            q.push(it);
            parent[it]=sh;
            visited[it]=1;
        }
        else if(visited[it] && it!=parent[sh]){
            return true;
        }
    }
}
return false;
}
void loopdetection(){
map<T,bool>visited;
map<T,T>parent;
for(auto it:adj){
    if(!visited[it.first]){
        if(BFSloop(visited,parent,it.first)){
            cout<<"Loop"<<endl;
            break;
        }
    }
}
}
};
int main(){
Graph<int>gr;
int m;
cout<<"Enter number of vetices: ";
cin>>m;
int n;
cout<<"Enter number of edges: ";
cin>>n;
for(int i=0;i<n;i++){
    int u,v;
    int d;
    cout<<"Enter vertices: ";
    cin>>v>>u;
    gr.add(u,v,0);
}
gr.print();
gr.BFStrav(2);
cout<<endl;
gr.DFStrav(2);
cout<<endl;
gr.loopdetection();
}