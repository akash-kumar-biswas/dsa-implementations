#include <bits/stdc++.h>
using namespace std;

void dijkstra(unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &dist, int src){
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if(d > dist[u])
            continue;

        for(auto neigh_v_w : adj[u]){
            int v = neigh_v_w.first;
            int w = neigh_v_w.second;
            if(w + dist[u] < dist[v]){
                dist[v] = w + dist[u];
                pq.push({dist[v], v});
            }
        }
    }
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
    dijkstra(adj, dist, 2); 
    for(auto it: dist){
        cout << it << " ";
    }
    return 0;
}