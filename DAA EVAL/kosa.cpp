#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, vector<int>> mpp;
    void AddEdge(int u, int v)
    {
        mpp[u].push_back(v);
        // mpp[v].push_back(u);
    }
    void print()
    {
        for (auto it : mpp)
        {
            cout << it.first << "->";
            for (auto ti : it.second)
            {
                cout << ti << ",";
            }
            cout << endl;
        }
    }
    void topo(unordered_map<int, bool> &visited, int node, stack<int> &s)
    {
        visited[node] = true;
        for (auto it : mpp[node])
        {
            if (!visited[it])
            {
                topo(visited, it, s);
            }
        }
        s.push(node);
    }
    void revdfs(unordered_map<int, bool> &visited, int node, unordered_map<int, vector<int>> &adj)
    {
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                revdfs(visited, it, adj);
            }
        }
    }
};
int main()
{
    Graph g;
    g.AddEdge(0, 1);
    g.AddEdge(1, 4);
    g.AddEdge(4, 0);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(3, 2);
    g.print();
    unordered_map<int, bool> visited;
    vector<int> ans;
    stack<int> s;
    unordered_map<int, vector<int>> adj;
    g.topo(visited, 0, s);
    for (auto it : g.mpp)
    {
        visited[it.first] = false;
        for (auto it1 : it.second)
        {
            adj[it1].push_back(it.first);
        }
    }
    int count = 0;
    while (!s.empty())
    {
        auto fnt = s.top();
        s.pop();
        if (!visited[fnt])
        {
            count++;
            g.revdfs(visited, fnt, adj);
        }
    }
    cout << count << endl;
}
