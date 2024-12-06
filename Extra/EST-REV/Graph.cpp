#include<bits/stdc++.h>
using namespace std;
template<class T>
class Graph{
    public:
    map<T,vector<T>>adj;
    void AdjList(T f, T s,int d){
        adj[f].push_back(s);
        if(d==0){
            adj[s].push_back(f);
        }
    }
    void print(){
        for(auto it:adj){
            cout<<it.first<<"->";
            for(auto it1:it.second){
                cout<<it1<<",";
            }
            cout<<endl;
        }
    }
    void bfs(vector<T>&ans,map<T,bool>&b,T node){
        queue<T>q;
        if(!b[node]) q.push(node);
        b[node]=true;
        while(!q.empty()){
            T front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto it:adj[front]){ 
                if(!b[it]){ 
                    b[it]=true;
                    q.push(it);
                    }
                }
        }
    }
    void dfs(vector<T>&ans,map<T,bool>&b,T node){
        if(!b[node]) ans.push_back(node);
        b[node]=true;
        for(auto it:adj[node]){
           if(!b[it]) dfs(ans,b,it);
        }
    }
    bool detectloopBFS(T node,map<T,bool>&visited,map<T,T>&parent){
        bool flag=0;
        queue<T>q;
        q.push(node);
        visited[node]=1;
        parent[node]=node;
        while(!q.empty()){
            T frontnode=q.front();
            q.pop();
            for(auto it:adj[frontnode]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                    parent[it]=frontnode;
                }
                else if(it!=parent[frontnode]){
                    flag=1;
                    return flag;
                }
            }
        }
        return flag;
    }
    void detectloop(){
        map<T,bool>visited;
        map<T,T>parent;
        for(auto it:adj){
            if(!visited[it.first]){
                if(detectloopBFS(it.first,visited,parent)){
                    cout<<"LOOOOOOOOOP"<<endl;
                    return;
                }
        }
        }
        cout<<"No loop"<<endl;
    }
};
int main(){
    Graph<int>g;
    int m,n;
    cout<<"Enter number of edges: ";
    cin>>n;
    cout<<"Enter number of vertices: ";
    cin>>m;
    for(int i=0;i<n;i++){
        int u,v;
        cout<<"Enter vertices: ";
        cin>>u>>v;
        int d=0;
        g.AdjList(u,v,d);
    }
    g.print();
    vector<int>ans;
    map<int,bool>b;
    //g.dfs(ans,b,1);
    g.detectloop();
    //for(auto it:ans) cout<<it<<endl;
}