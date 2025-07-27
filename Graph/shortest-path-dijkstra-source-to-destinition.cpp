#include <bits/stdc++.h>
using namespace std;

void dijkstra(unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &dist, vector<int> &parent, int src)
{
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto neigh_v_w : adj[u])
        {
            int v = neigh_v_w.first;
            int w = neigh_v_w.second;
            if (w + dist[u] < dist[v])
            {
                dist[v] = w + dist[u];
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

void shortestPath(vector<int> &parent, vector<int> &ans, int node)
{
    if (parent[node] == -1)
    {
        ans.push_back(node);
        return;
    }
    shortestPath(parent, ans, parent[node]);
    ans.push_back(node);
}

int main()
{
    unordered_map<int, vector<pair<int, int>>> adj;

    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dijkstra(adj, dist, parent, 1);
    vector<int> ans;
    shortestPath(parent, ans, 2);
    for (auto v : ans)
    {
        cout << v << " ";
    }
    return 0;
}