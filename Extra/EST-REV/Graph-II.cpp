#include<bits/stdc++.h>
using namespace std;
template<class T>
class Graph{
    public:
    map<T,vector<pair<T,T>>>mpp;
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
    void dfs(map<T,bool>&visited,stack<T>&s,T node){
        visited[node]=true;
        for(auto it:mpp[node]){
            if(!visited[it.first]) dfs(visited,s,it.first);
        }
        s.push(node);
    }
    void shortestPath(vector<T>&distance,map<T,bool>&visited,stack<T>&s,T node){
        distance[node]=0;
        while(!s.empty()){
            auto front=s.top();
            s.pop();
            for(auto it:mpp[front]){
                if(distance[front]!=INT_MAX && it.second+distance[front]<distance[it.first]){
                        distance[it.first]=it.second+distance[front];
                    }
                }
            }
        }
    void Dijkstra(vector<T>&distance,set<pair<T,T>>&st,T node){
        st.insert({0,node});
        while(!st.empty()){
            auto front=*(st.begin());
            int nodedis=front.first;
            int nodefront=front.second;
            st.erase(st.begin());
            for(auto it:mpp[nodefront]){
                if(nodedis+it.second<distance[it.first]){
                    auto record=st.find({distance[it.first],it.first});
                    if(record!=st.end()){
                        st.erase({distance[it.first],it.first});
                    }
                    distance[it.first]=nodedis+it.second;
                    st.insert({distance[it.first],it.first});
                }
            }
        }
    }
};
int main(){
Graph<int>g;
    g.Adj(0, 1, 4);
    g.Adj(0, 7, 8);
    g.Adj(1, 2, 8);
    g.Adj(1, 7, 11);
    g.Adj(2, 3, 7);
    g.Adj(2, 8, 2);
    g.Adj(2, 5, 4);
    g.Adj(3, 4, 9);
    g.Adj(3, 5, 14);
    g.Adj(4, 5, 10);
    g.Adj(5, 6, 2);
    g.Adj(6, 7, 1);
    g.Adj(6, 8, 6);
    g.Adj(7, 8, 7);
    g.adjprint();
    // map<int,bool>visited;
    // stack<int>s;
    // for(int i=0;i<6;i++){
    //   if(!visited[i]){
    //     visited[i]=1;
    //     g.dfs(visited,s,i);
    //     }
    // }
    vector<int>ans;
    vector<int>distance(9,INT_MAX);
    //g.shortestPath(distance,visited,s,1);
    set<pair<int,int>>st;
    distance[0]=0;
    g.Dijkstra(distance,st,1);
    for(auto it:distance) cout<<it<<" ";
}