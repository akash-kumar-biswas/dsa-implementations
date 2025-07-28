#include<bits/stdc++.h>
using namespace std;

void bellmanFord(unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &dist, int V, int src){
    dist[src] = 0;

    for(int i = 1; i < V; i++){
        for(int u = 0; u < V; u++){
            for(auto edge: adj[u]){
                int v = edge.first;
                int w = edge.second;

                if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
    }

    for(int u = 0; u < V; u++){
        for(auto edge: adj[u]){
            int v = edge.first;
            int w = edge.second;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                cout << "Negative edge weight cycle exists" << endl;
                return;
            }
        }
    }

    cout << "shortest path from " << src << " to all other vertices : ";

    for(auto it: dist){
        cout << it << " ";
    }
}

int main(){
    unordered_map<int, vector<pair<int, int>>> adj;

    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(V, INT_MAX);
    bellmanFord(adj, dist, V, 0);
    return 0;
}