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
    void bfs(int i, unordered_map<int, bool> &vis, vector<int> &ans)
    {
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int fnt = q.front();
            q.pop();
            ans.emplace_back(fnt);
            for (auto it : mpp[fnt])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
    }
    void dfs(int i, unordered_map<int, bool> &visited, vector<int> &ans)
    {
        visited[i] = true;
        ans.push_back(i);
        for (auto it : mpp[i])
        {
            if (!visited[it])
            {
                dfs(it, visited, ans);
            }
        }
    }
    void Kahn(int i, vector<int> &ans)
    {
        vector<int> in(10, 0);
        for (auto it : mpp)
        {
            for (auto j : it.second)
            {
                in[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < in.size(); ++i)
        {
            if (in[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int fnt = q.front();
            ans.emplace_back(fnt);
            q.pop();
            for (auto it : mpp[fnt])
            {
                in[it]--;
                if (in[it] == 0)
                {
                    q.push(it);
                }
            }
        }
    }
    void KosaDFS(int i, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[i] = 1;
        for (auto it : mpp[i])
        {
            if (!visited[it])
            {
                KosaDFS(it, visited, s);
            }
        }
        s.push(i);
    }
    void rdfs(stack<int> &s, unordered_map<int, vector<int>> &pmm, unordered_map<int, bool> &visited)
    {
        int count = 0;
        while (!s.empty())
        {
            int fnt = s.top();
            s.pop();
            if (!visited[fnt])
            {
                visited[fnt] = 1;
                count++;
                rdfs(s, pmm, visited);
            }
        }
        cout << count << endl;
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
    g.KosaDFS(0, visited, s);
    unordered_map<int, vector<int>> pmm;
    for (auto it : g.mpp)
    {
        visited[it.first] = false;
        for (auto it1 : it.second)
        {
            pmm[it1].push_back(it.first);
        }
    }
    g.rdfs(s, pmm, visited);
    // g.Kahn(0, ans);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     if (!visited[i])
    //     {
    //         visited[i] = true;
    //         g.bfs(i, visited, ans);
    //     }
    // }
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     if (!visited[i])
    //     {
    //         visited[i] = true;
    //         g.dfs(i, visited, ans);
    //     }
    // }
}