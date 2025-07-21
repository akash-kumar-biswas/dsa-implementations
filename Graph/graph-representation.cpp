#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int, vector<int>> adj;    //directed Graph (DG)

    int E;
    cin>>E;

    for(int i = 1; i <= E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    cout<<"\n";

    for(auto vec: adj){
        for(auto v: vec.second){
            cout<<vec.first<<" "<<v<<"\n";     //print edges of DG  , vec.first-->u
        }
    }
    return 0;
}