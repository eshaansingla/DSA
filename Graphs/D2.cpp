#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
private:
    map<T, vector<T>> adj;

public:
    void add(T f, T s, int dxn)
    {
        adj[f].emplace_back(s);
        if (dxn == 0)
            adj[s].emplace_back(f);
    }
    void print()
    {
        for (auto it : adj)
        {
            cout << it.first << "->";
            for (auto it1 : it.second)
                cout << it1 << ",";
            cout << endl;
        }
    }
    void bfs(vector<T> &ans, T node, map<T, bool> &b)
    {
        queue<T> q;
        q.push(node);
        b[node] = 1;
        while (!q.empty())
        {
            auto res = q.front();
            q.pop();
            ans.push_back(res);
            for (auto it : adj[res])
            {
                if (!b[it])
                {
                    q.push(it);
                    b[it] = 1;
                }
            }
        }
    }
};
int main()
{
    printf("hi");
}