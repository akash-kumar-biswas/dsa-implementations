#include <bits/stdc++.h>
using namespace std;

void topoSortBfs(unordered_map<int, vector<int>> &adj, vector<int> &inDegree, vector<int> &ans){
    queue<int> q;
    for(int i = 0; i < inDegree.size(); i++){
        if(inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        for (auto neigh : adj[u])
        {
            inDegree[neigh]--;
            if(inDegree[neigh] == 0)
                q.push(neigh);
        }
        ans.push_back(u);
        q.pop();
    }
}

int main()
{
    unordered_map<int, vector<int>> adj;

    int V, E;
    cin >> V >> E;

    vector<int> inDegree(V, 0);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    vector<int> ans;
    topoSortBfs(adj, inDegree, ans);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}