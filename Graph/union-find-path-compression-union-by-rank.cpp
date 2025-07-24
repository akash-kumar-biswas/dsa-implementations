#include<bits/stdc++.h>
using namespace std;

int find(int i, vector<int> &parent){
    if(-1 == parent[i])
        return i;
    return parent[i]=find(parent[i], parent);
}

void _union(int a, int b, vector<int> &parent, vector<int> &rank){
    int root_a = find(a, parent);
    int root_b = find(b, parent);
    if(root_a != root_b){
        if(rank[root_a] > rank[root_b])
            parent[root_b] = root_a;
        else if(rank[root_a] < rank[root_b])
            parent[root_a] = root_b;
        else{
            parent[root_a] = root_b;
            rank[root_b]++;
        }
    }
}

int main(){
    vector<int> parent(6);
    fill(parent.begin(), parent.end(), -1);
    
    vector<int> rank(6, 0);
    _union(1, 2, parent, rank);
    for(int i = 1; i <= 5; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i = 1; i <= 5; i++){
        cout << parent[i] << " ";
    }

    _union(1, 3, parent, rank);
    cout << endl;
    for(int i = 1; i <= 5; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i = 1; i <= 5; i++){
        cout << parent[i] << " ";
    }
    cout << endl;
    cout << find(1, parent) << endl;
    for(int i = 1; i <= 5; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i = 1; i <= 5; i++){
        cout << parent[i] << " ";
    }
    return 0;
}