#include<bits/stdc++.h>
using namespace std;
template<class T>
class Graph{
    public:
    map<T,vector<T>>adj;
    unordered_map<T,vector<pair<T,int>>>mpp;
    void dfsAdj(T i,map<T,bool>&visit,stack<T>&s){
        visit[i]=true;
        for(auto it1:mpp[i]){
            if(!visit[it1.first]){
                dfsAdj(it1.first,visit,s);
            }
        }
        s.push(i);
    }
    void Adj(T f,T s,int d){
        mpp[f].emplace_back(s,d);
    }
    void adjprint(){
        for(auto it:mpp){
            cout<<it.first<<"->";
            for(auto it1:it.second){
                cout<<"("<<it1.first<<","<<it1.second<<")";
            }
            cout<<endl;
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
    void dfstopo(map<T,bool>&visited,stack<T>&st,T node){
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfstopo(visited,st,it);
        }
        }
        st.push(node);
    }
    void TopoSort(vector<T>&ans){
        map<T,bool>visited;
        stack<T>st;
        for(auto it:adj){
            if(!visited[it.first]){
                dfstopo(visited,st,it.first);
            }
        }
        while(!st.empty()){
            ans.emplace_back(st.top());
            st.pop();
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
    bool detectloopDFS(T node,map<T,bool>&visited,map<T,T>&parent){
        visited[node]=1;
        for(auto it:adj[node]){
           if(!visited[it]){
            parent[it]=node;
            bool ans=detectloopDFS(it,visited,parent);
            if(ans) return true;
             }
           else if(it!=parent[node]){
                return true;
           }
        }
        return false;
    }
    void detectloop(){
        map<T,bool>visited;
        map<T,T>parent;
        for(auto it:adj){
            if(!visited[it.first]){
                if(detectloopDFS(it.first,visited,parent)){
                    cout<<"LOOOOOOOOOP"<<endl;
                    return;
                }
        }
        }
        cout<<"No loop"<<endl;
    }
    bool DirectedLoop(map<T,bool>&visited,map<T,bool>&dfsvisited,T node){
        dfsvisited[node]=1;
        visited[node]=1;
        for(auto it:adj[node]){ 
            if(!visited[it]){
            bool ans= DirectedLoop(visited,dfsvisited,it);
            if(ans) return true;
        }
        else if(dfsvisited[it]) return true;
        }
        dfsvisited[node]=0;
        return false;
    }
    void detectloopDir(){
        map<T,bool>visited;
        map<T,bool>dfsvisited;
        for(auto it:adj){
            if(!visited[it.first]){
                visited[it.first]=true;
                if(DirectedLoop(visited,dfsvisited,it.first)){
                    cout<<"LOOOOOOOP"<<endl;
                    return;
                }
            }
        }
        cout<<"NO LOOP."<<endl;
    }
    void Kahn(vector<T>&ans){
        map<T,int>indegree;
        queue<T>q;
        for(auto it:adj){
            for(auto it1:it.second){
                indegree[it1]++;
            }
        }
        for(auto it:adj){
            if(indegree[it.first]==0) q.push(it.first);
        }
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            ans.emplace_back(f);
            for(auto it:adj[f]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
    }
    void shortestPath(){
        T source=1;
        T destination=8;
        queue<T>q;
        vector<T>ans;
        map<T,T>parent;
        map<T,bool>visited;
        parent[source]=-1;
        visited[source]=true;
        q.push(source);
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            for(auto it:adj[front]){
               if(!visited[it]){
                visited[it]=true;
                parent[it]=front;
                q.push(it);
               }
            }
        }
        ans.emplace_back(destination);
        while(source!=destination){
            ans.emplace_back(parent[destination]);
            destination=parent[destination];
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans) cout<<it<<" ";
    }
    void getShortestPath(T src,map<T,int>&dis,stack<T>&st){
        dis[src]=0;
        while(!st.empty()){
            int fr=st.top();
            st.pop();
            if(dis[fr]!=INT_MAX){
                for(auto m:mpp[fr]){
                if(dis[fr]+m.second<dis[m.first]){
                    dis[m.first]=dis[fr]+m.second;
                }
                }
            }
        }
    }
};
int main(){
    Graph<int>g;
    /*
    int m,n;
    cout<<"Enter number of edges: ";
    cin>>n;
    cout<<"Enter number of vertices: ";
    cin>>m; 
    for(int i=0;i<n;i++){
        int u,v;
        cout<<"Enter vertices: ";
        cin>>u>>v;
        int d=1;
        g.AdjList(u,v,d);
    }
    g.print();
    vector<int>ans;
    map<int,bool>b;
    */
    //g.dfs(ans,b,1);
    //g.detectloopDir();
    //g.TopoSort(ans);
    // g.Kahn(ans);
    // for(auto it:ans) cout<<it<<endl;
    // if(ans.size()!=m) cout<<"looop"<<endl;
    // else cout<<"no loop....."<<endl;
    //g.shortestPath();
    g.Adj(0,1,5);
    g.Adj(0,2,3);
    g.Adj(1,2,2);
    g.Adj(1,3,6);
    g.Adj(2,3,7);
    g.Adj(2,4,4);
    g.Adj(2,5,2);
    g.Adj(3,4,-1);
    g.Adj(4,5,-2);
    g.adjprint();
    int n=6;
    map<int,bool>visit;
    stack<int>s;
    vector<int>sol;
    for(int i=0;i<n;i++){
        if(!visit[i]){
            visit[i]=1;
            g.dfsAdj(i,visit,s);
        }
    }
    int src=1;
    // while(!s.empty()){
    //     sol.emplace_back(s.top());
    //     s.pop();
    // }
    for(auto it:sol) cout<<it<<" ";
    map<int,int>dis;
    for (int i = 0; i < n; i++) {
    dis[i] = INT_MAX;
}
    g.getShortestPath(src,dis,s);
    cout<<endl;
    for(auto it:dis) cout<<it.second<<" ";
}