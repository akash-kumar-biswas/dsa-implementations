#include <bits/stdc++.h>
using namespace std;

bool isNotBipartiteBfs(unordered_map<int, vector<int>> &adj, vector<int> &color, int u, int currColor)
{
    queue<int> q;
    color[u] = currColor;
    q.push(u);

    while (!q.empty())
    {
        u = q.front();

        for (auto neigh : adj[u])
        {
            if (color[neigh] == color[u])
                return true;

            if (color[neigh] == -1)
            {
                color[neigh] = 1 ^ color[u];
                q.push(neigh);
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

        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1 && isNotBipartiteBfs(adj, color, i, 1))
            {
                cout << "Not Bipartite" << endl;
                return 0;
            }
        }
        cout << "It is Bipartite" << endl;
        return 0;
    }