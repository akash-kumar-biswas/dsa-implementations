#include <bits/stdc++.h>
using namespace std;

bool isCycleBfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int u){
    queue<pair<int, int>> q;
    visited[u] = true;
    q.push({u, -1});

    while (!q.empty())
    {
        u = q.front().first;
        int parent = q.front().second;

        for (auto neigh : adj[u])
        {
            if (visited[neigh] && parent != neigh)
                return true;
            if (!visited[neigh])
            {
                visited[neigh] = true;
                q.push({neigh, u});
            }
        }
        q.pop();
    }
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
        adj[v].push_back(u);
    }
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && isCycleBfs(adj, visited, i))
        {
            cout << "Cycle Exists" << endl;
            return 0;
        }
    }
    cout << "Cycle doesn't exist" << endl;
    return 0;
}