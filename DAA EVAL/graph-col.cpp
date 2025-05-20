#include <iostream>
#include <vector>
using namespace std;

#define V 4
bool isSafe(vector<vector<int>> &graph, int m, int v, vector<int> &color, int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && color[i] == c)
        {
            return false;
        }
    }
    return true;
}
bool solver(vector<vector<int>> &graph, int m, int v, vector<int> &color)
{
    if (v == V)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(graph, m, v, color, i))
        {
            color[v] = i;
            if (solver(graph, m, v + 1, color))
                return true;
            color[v] = 0;
        }
    }
    return false;
}
void graphColoring(vector<vector<int>> &graph, int m)
{
    vector<int> color(V, 0);
    if (!solver(graph, m, 0, color))
    {
    }
    else
    {
        for (auto it : color)
            cout << it << " ";
    }
}
int main()
{
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};

    int m = 3; // Number of colors
    graphColoring(graph, m);

    return 0;
}
