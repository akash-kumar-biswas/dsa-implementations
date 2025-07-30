#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int level = 0;
    while(!q.empty()){
        int n = q.size();  //nodes at current level

        while(n--){
            int u = q.front();   // process all nodes of current level
            q.pop();
            for(auto neigh: adj[u]){
                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }
        level++; // 1 level processed (move to the next level)
    }
    cout << "Total levels: " << level << endl;
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
    bfs(adj, visited, 2);
    return 0;
}