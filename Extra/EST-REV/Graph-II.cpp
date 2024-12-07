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
                }}
        }
    }
    };
int main(){
Graph<int>g;
    g.Adj(0,1,2);
    g.Adj(1,2,3);
    g.Adj(0,3,6);
    g.Adj(1,4,5);
    g.adjprint();
    // map<int,bool>visited;
    // stack<int>s;
    // for(int i=0;i<6;i++){
    //   if(!visited[i]){
    //     visited[i]=1;
    //     g.dfs(visited,s,i);
    //     }
    // }
//     vector<int>ans;
//     vector<int>distance(4,INT_MAX);
//     //g.shortestPath(distance,visited,s,1);
//     set<pair<int,int>>st;
//     distance[0]=0;
//     vector<int>parent;
//     vector<bool>mst(4,false);
//     parent[0]=0;
//     //g.Dijkstra(distance,st,1);
//     g.Prim(distance, parent, mst);
//   for (int i = 1; i < 4; i++) {
//         if (parent[i] != -1) {
//             cout << parent[i] << " - " << i << " : " << distance[i] << endl;
//         }
//     }
 int n = g.mpp.size();
    map<int,int>distance;
    map<int,int> parent;
    for(auto it:distance){
        it.second=INT_MAX;
    }
    map<int,bool> mst;

    for(auto it:parent) cout<<it.second<<endl;
}