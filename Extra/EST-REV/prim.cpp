#include<bits/stdc++.h>
using namespace std;
template<class T>
class Graph{
    public:
    map<T,vector<pair<T,T>>>mpp;
    void Adj(T f,T s,int d){
        mpp[f].emplace_back(s,d);
        mpp[s].emplace_back(f,d);
    }
    void adjprint(){
        for(auto it:mpp){
            cout<<it.first<<"->";
            for(auto it1:it.second){
                cout<<"("<<it1.first<<","<<it1.second<<")"<<" ";
            }
            cout<<endl;
        }
    }
    void Prim(map<int,bool>&mst,map<int,int>&parent,vector<int>&distance){
        int n=mpp.size();
        for(int i=0;i<=n;i++){
            int u=-1;
            for(int j=0;j<n;j++){
                if(!mst[j] && (u==-1 || distance[u]>distance[j])){
                    u=j;
                }
            }
            mst[u]=1;
            for(auto it:mpp[u]){
                T node=it.first;
                int dis=it.second;
                if(!mst[node] && distance[node]>it.second){
                    distance[node]=it.second;
                    parent[node]=u;
                }
            }
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
    map<int,bool>mst;
    map<int,int>parent;
    vector<int>distance(5,INT_MAX);
    distance[0]=0;
    g.Prim(mst,parent,distance);
    for(auto it:parent) cout<<it.first<<" ";
    cout<<endl;
    for(auto it:distance) cout<<it<<" ";
}