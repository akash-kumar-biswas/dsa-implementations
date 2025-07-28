#include <bits/stdc++.h>
using namespace std;

int find(int i, vector<int> &parent)
{
    if (parent[i] == -1)
        return i;
    return parent[i] = find(parent[i], parent);
}

void _union(int a, int b, vector<int> &parent, vector<int> &rank)
{
    int root_a = find(a, parent);
    int root_b = find(b, parent);
    if (root_a != root_b)
    {
        if (rank[root_a] > rank[root_b])
            parent[root_b] = root_a;
        else if (rank[root_a] < rank[root_b])
            parent[root_a] = root_b;
        else
        {
            parent[root_a] = root_b;
            rank[root_b]++;
        }
    }
}

void kruskal(vector<pair<int, pair<int, int>>> &edgeList, int V)
{
    sort(edgeList.begin(), edgeList.end());

    vector<int> parent(V, -1);
    vector<int> rank(V, 0);

    vector<pair<int, pair<int, int>>> possibleMST;

    for (auto edge : edgeList)
    {
        int u = edge.second.first;
        int v = edge.second.second;

        if(find(u, parent) != find(v, parent)){
            possibleMST.push_back(edge);
            _union(u, v, parent, rank);
        }
    }

    cout << "Possible MST's  edges (u, v, w): " << endl;

    for(auto edge: possibleMST){
        cout << edge.second.first << " " << edge.second.second << " " << edge.first << endl;
    }
}

int main()
{
    int V, E;
    cout << "Enter no of vertices and edges: " << endl;
    cin >> V >> E;

    vector<pair<int, pair<int, int>>> edgeList;
    cout << "Enter u, v, w: " << endl;
    for (int i = 1; i <= E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back({w, {u, v}});
    }

    kruskal(edgeList, V);
    return 0;
}