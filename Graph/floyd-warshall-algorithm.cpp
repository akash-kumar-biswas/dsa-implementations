#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &dist, int V){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){

                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 0; i < V; i++){
        if(dist[i][i] < 0){
            cout << "Negative edge weight cycle exist" << endl;
            return;
        }
    }

    cout << "All pairs shortest path : " << endl;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            (dist[i][j] != INT_MAX) ? cout << dist[i][j] << " " : cout << "INF ";
        }
        cout << endl;
    }
}

int main(){
    int V, E;
    cin >> V >> E;

    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    for(int i = 0; i < V; i++)
        dist[i][i] = 0;
    
    while(E--){
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    floydWarshall(dist, V);
    return 0;
}