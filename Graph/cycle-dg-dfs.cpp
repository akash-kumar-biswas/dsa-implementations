#include <bits/stdc++.h>
using namespace std;

bool isCycleDfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion, int u)
{
    visited[u] = true;
    inRecursion[u] = true;
    for (auto neigh : adj[u])
    {
        if (visited[neigh] && inRecursion[neigh])
            return true;

        if (!visited[neigh] && isCycleDfs(adj, visited, inRecursion, neigh))
            return true;
    }
    inRecursion[u] = false;
    return false;
}

int main()
{
    unordered_map<int, vector<int>> adj;

    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<bool> visited(V, false);
    vector<bool> inRecursion(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && isCycleDfs(adj, visited, inRecursion, i))
        {
            cout << "Cycle Exists" << endl;
            return 0;
        }
    }
    cout << "Cycle doesn't exist" << endl;
    return 0;
}