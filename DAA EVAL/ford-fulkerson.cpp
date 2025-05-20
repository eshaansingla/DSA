#include <bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>> &graph, vector<int> &parent, int s, int t)
{
    int n = graph.size();
    vector<bool> visited(n, 0);
    queue<int> q;
    parent[s] = -1;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        auto fnt = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && graph[fnt][i] > 0)
            {
                visited[i] = true;
                parent[i] = fnt;
                q.push(i);
                if (t == i)
                    return true;
            }
        }
    }
    return false;
}
int fordFulkerson(vector<vector<int>> &graph, int s, int t)
{
    vector<vector<int>> res = graph;
    int n = graph.size();
    int maxflow = 0;
    vector<int> parent(n);
    while (bfs(res, parent, s, t))
    {
        int pathflow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            pathflow = min(pathflow, res[u][v]);
        }
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            res[u][v] -= pathflow;
            res[v][u] += pathflow;
        }
        maxflow += pathflow;
    }
    return maxflow;
}
int main()
{
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};
    int s = 0, t = 5;
    cout << "Maximum Flow: " << fordFulkerson(graph, s, t) << endl;
    return 0;
}