#include<bits/stdc++.h>
using namespace std;

bool isNotBipartiteDfs(unordered_map<int, vector<int>> &adj, vector<int> &color, int u, int currColor){
    color[u] = currColor;

    for(auto neigh: adj[u]){
        if(color[neigh] == currColor)
            return true;
        if(color[neigh] == -1){
            color[neigh] = 1 ^ currColor;
            if(isNotBipartiteDfs(adj, color, neigh, color[neigh]))
                return true;
        }
    }
    return false;
}

int main(){
    unordered_map<int, vector<int>> adj;   

    int V, E;
    cin >> V >> E;

    for(int i = 0; i < E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(V, -1);
    for(int i = 0; i < V; i++){
        if(color[i] == -1 && isNotBipartiteDfs(adj, color, i, 1)){
            cout << "Not Bipartite" << endl;
            return 0;
        }
    }
    cout << "It is Bipartite" << endl;
    return 0;
}