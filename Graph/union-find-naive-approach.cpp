#include<bits/stdc++.h>
using namespace std;

int find(int i, vector<int> &parent){
    if(-1 == parent[i])
        return i;
    return find(parent[i], parent);
}

void _union(int a, int b, vector<int> &parent){
    int root_a = find(a, parent);
    int root_b = find(b, parent);
    if(root_a != root_b)
        parent[root_b] = root_a;
}

int main(){
    vector<int> parent(6);
    fill(parent.begin(), parent.end(), -1);
    
    _union(1, 2, parent);
    for(int i = 1; i <= 5; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i = 1; i <= 5; i++){
        cout << parent[i] << " ";
    }

    _union(2, 3, parent);
    cout << endl;
    for(int i = 1; i <= 5; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i = 1; i <= 5; i++){
        cout << parent[i] << " ";
    }
    return 0;
}