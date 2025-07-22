#include<bits/stdc++.h>
using namespace std;

void topoSortDfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited,stack<int> &stk, int u){
    visited[u] = true;
    for(auto neigh: adj[u]){
        if(!visited[neigh])
            topoSortDfs(adj, visited, stk, neigh);
    }
    stk.push(u);
}

int main(){
    unordered_map<int, vector<int>> adj;   

    int V, E;
    cin >> V >> E;

    for(int i = 0; i < E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    vector<bool> visited(V, false);
    stack<int> stk;
    for(int i = 0; i < V; i++){
        if(!visited[i])
            topoSortDfs(adj, visited, stk,i);
    }
    while(!stk.empty()){
        cout << stk.top()<<" ";
        stk.pop();
    }
    return 0;
}