#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int u){
    queue<int> q;
    cout<< u << endl;
    q.push(u);
    visited[u] = true;

    while(!q.empty()){
        u = q.front();

        for(auto neigh: adj[u]){
            if(!visited[neigh]){
                cout<< neigh << endl;
                q.push(neigh);
                visited[neigh] = true;
            }
        }
        q.pop();
    }
    
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
    vector<bool> visited(V, false);
    bfs(adj, visited, 0);
    return 0;
}