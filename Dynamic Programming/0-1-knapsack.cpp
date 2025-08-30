#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int knapsack(vector<int> &w, vector<int> &profit, int W, int i){
    if(W == 0 || i >= w.size())
        return 0;
    
    if(dp[i][W] != -1)
        return dp[i][W];

    if(w[i] > W)
        return dp[i][W] = knapsack(w, profit, W, i+1);
    
    int take = profit[i] + knapsack(w, profit, W-w[i], i+1);
    int skip = knapsack(w, profit, W, i+1);

    return dp[i][W] = max(take, skip);
}

int main(){
    vector<int> w = {3, 4, 1};
    vector<int> profit = {5, 6, 1};
    int W = 7;

    dp.assign(w.size(), vector<int>(W + 1, -1));

    cout << "Max Profit: " << knapsack(w, profit, W, 0);
}
